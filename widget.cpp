#include "widget.h"
#include "ui_widget.h"
#include "nameplaylist.h"

#include <QFileDialog>
#include <QDir>
#include <QPalette>
#include <QByteArray>
#include <QSqlRecord>
#include <QSqlError>
#include <QTableView>
#include <QTableWidgetItem>
#include <QVariant>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
   //Подключаем базу данных
    sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName("C:\\Users\\dns\\Desktop\\Qt\\SQLiteDatabaseBrowserPortable\\Data\\audio.sqlite");
   ui->setupUi(this);
   ui->listWidget->addItem("Основной плейлист");//плейлист по умолчанию

   // Настройка таблицы плейлиста
   m_playListModel = new QStandardItemModel(this);
   m_player = new QMediaPlayer(this);          // Инициализируем плеер
   m_playlist = new QMediaPlaylist(m_player);  // Инициализируем плейлист
   if(!sdb.open()) qDebug() << sdb.lastError().text();

     QSqlQuery query= QSqlQuery (sdb);
   //пересичляем существующие плейлисты
   query.prepare("select * from NameList");
   if (!query.exec()) {
          qDebug() << query.lastError().databaseText();
          qDebug() << query.lastError().driverText();
     }
      while (query.next())
         {
          //query.record(2)
           ui->listWidget->addItem(query.value(1).toString());//плейлист по умолчанию
      }
     sdb.close();

   Init();
   Player(numberList);

    // подключаем кнопки управления к слотам управления
    // Здесь отметим, что навигация по плейлисту осуществляется именно через плейлист
   connect(ui->btn_play, &QToolButton::clicked, m_player, &QMediaPlayer::play);
   connect(ui->btn_stop, &QToolButton::clicked, m_player, &QMediaPlayer::stop);
   connect(ui->btn_pause, &QToolButton::clicked, m_player, &QMediaPlayer::pause);
   ui->delete_playlist->setEnabled(false);
   ui->SetNumberPlaylist->setEnabled(false);
     // connect(ui->delete_playlist, SIGNAL(clicked()), ui->delete_playlist, SLOT(False()));
   // При клике по треку в таблице устанавливаем трек в плейлисте
   connect(ui->playlistView, &QTableView::clicked, [this](const QModelIndex &index){
          m_playlist->setCurrentIndex(index.row());
      });
   QObject:: connect(ui->playlistView, SIGNAL(doubleClicked(QModelIndex)), SLOT(Delete_one()));

}


void Widget:: Delete_one(){
    int row = ui->playlistView->currentIndex().row();
    int idPlay = numberList;
    QVariant myData; //Сюда положим данные из ячейки
    QModelIndex myIndex;
    myIndex = ui->playlistView->model()->index( row, 1, QModelIndex()); // row, column это интересующая вас ячейка
    myData = ui->playlistView->model()->data( myIndex, Qt::DisplayRole); // role это интересующая вас роль, например Qt::DisplayRole
    //данные в QVariant приводите к чему хотите и обрабатывайте
   QString names=myData.toString();
    qDebug()<< myData.toString();

   if(!sdb.open()) qDebug() << sdb.lastError().text();

     QSqlQuery query= QSqlQuery (sdb);
     //qDebug()<< "row="<<row<<"and"<<numberList;
     query.prepare("delete from List where name=:names and id=:row and idPlayer=:idPlay;");
     query.bindValue(":names", names );
     query.bindValue(":row", row+1 );
     query.bindValue(":idPlay", idPlay );

     while (query.next())
        {
         qDebug()<<query.first();
         }
     qDebug()<< query.exec();
     int i=row+1;
     while(m_playListModel->rowCount()-i>0){
         query.prepare("update List set id=:row1 where id=:row2 ;");
         query.bindValue(":row1", i );
         query.bindValue(":row2", i+1 );
         query.exec();
         i=i+1;
     }
      sdb.close();
      m_playListModel->clear();
      ui->playlistView->model()->removeRow(row);
      m_playlist->clear();
      Init();
      Player(numberList);
}


Widget::~Widget()
{
 delete ui;
 delete m_playListModel;
 delete m_playlist;
 delete m_player;
}

void Widget:: Init()
{

    ui->playlistView->setModel(m_playListModel);    // Устанавливаем модель данных в TableView
    // Устанавливаем заголовки таблицы
    m_playListModel->setHorizontalHeaderLabels(QStringList()<< tr("Audio Track") << tr("File Path"));

    ui->playlistView->setEditTriggers(QAbstractItemView::NoEditTriggers);   // Отключаем редактирование
    ui->playlistView->hideColumn(1);    // Скрываем колонку, в которой хранится путь к файлу
    ui->playlistView->verticalHeader()->setVisible(false);                  // Скрываем нумерацию строк
    //ui->playlistView->setSelectionBehavior(QAbstractItemView::SelectRows);  // Включаем выделение строк
    // Включаем подгонку размера последней видимой колонки к ширине TableView
    ui->playlistView->horizontalHeader()->setStretchLastSection(true);

    m_player->setPlaylist(m_playlist);          // Устанавливаем плейлист в плеер
    m_player->setVolume(70);                    // Устанавливаем громкость воспроизведения треков
    m_playlist->setPlaybackMode(QMediaPlaylist::Loop);  // Устанавливаем циклический режим проигрывания плейлиста

}
void Widget:: Player(int number){

    if(!sdb.open()) qDebug() << sdb.lastError().text();

    QSqlQuery query= QSqlQuery (sdb);
    query.prepare("select * from List where idPlayer=:number");
    query.bindValue(":number", number);
      if (!query.exec()) {
           qDebug() << query.lastError().databaseText();
           qDebug() << query.lastError().driverText();
      }
       while (query.next())
          {
           QString filePath = query.value(1).toString();
           QList<QStandardItem *> items;
           items.append(new QStandardItem(QDir(filePath).dirName()));
           items.append(new QStandardItem(filePath));
           m_playListModel->appendRow(items);
           m_playlist->addMedia(QUrl(filePath));
           }
      sdb.close();

 }
void Widget::on_btn_add_clicked()
{
 // С помощью диалога выбора файлов делаем множественный выбор mp3 файлов
 QStringList files = QFileDialog::getOpenFileNames(this,tr("Open files"),QString(),tr("Audio Files (*.mp3)"));

  // Далее устанавливаем данные по именам и пути к файлам
 // в плейлист и таблицу отображающую плейлист
 foreach (QString filePath, files) {
     QList<QStandardItem *> items;
     items.append(new QStandardItem(QDir(filePath).dirName()));
     items.append(new QStandardItem(filePath));

     QString streamm = filePath;
     qDebug()<<streamm;
     int id = m_playListModel->rowCount()+1;
     qDebug()<< "id = "<< id;
     m_playListModel->appendRow(items);
     m_playlist->addMedia(QUrl(filePath));
        //Осуществляем запрос
     if(!sdb.open()) qDebug() << sdb.lastError().text();
     QSqlQuery query= QSqlQuery (sdb);
     query.prepare("insert into List('id','name','idPlayer') values(:id, :stream, :number);");//добавление данных
     query.bindValue(":stream", streamm);
     query.bindValue(":number", numberList);
      query.bindValue(":id", id);
     if(!query.exec()){
            qDebug() << "error insert into ";
            qDebug() << query.lastError().text();
     }

     sdb.close();

 }
}

void Widget::on_NewPlayList_clicked()
{
    NamePlayList window1;

    window1.setModal(true);
    window1.exec();
    QString data = window1.getInput();
    if(!data.isEmpty()){
    int number=ui->listWidget->count();
     ui->listWidget->addItem(data);
    if(!sdb.open()){
           qDebug() << sdb.lastError().text();
            qDebug() << "error open playlist ";
       }
       QSqlQuery query= QSqlQuery (sdb);
       query.prepare("insert into namelist('namelist','idlist') values(:name, :num);");//добавление нового плейлиста
       query.bindValue(":name", data);
        query.bindValue(":num", number);
       if(!query.exec()){
              qDebug() << "error insert into ";
              qDebug() << query.lastError().text();
       }

       sdb.close();
    }else QMessageBox::information(this, "Ошибка", "Попробуйте создать снова!");

}

void Widget::on_SetNumberPlaylist_clicked() //переключение на выбранный плейлист
{
    numberList = ui->listWidget->currentIndex().row();
    m_playListModel->clear();
    m_playlist->clear();
    Init();
    Player(numberList);
    qDebug()<<numberList;
}

void Widget::on_btn_next_clicked()
{
    m_playlist->next();
    ui->playlistView->selectRow( m_playlist->currentIndex());
    ui->playlistView->setSelectionBehavior(QAbstractItemView::SelectRows);

}

void Widget::on_btn_previous_clicked()
{
    m_playlist->previous();
    ui->playlistView->selectRow( m_playlist->currentIndex());
    ui->playlistView->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void Widget::on_delete_playlist_clicked()
{
    ui->delete_playlist->setEnabled(false);
    int numderDelet = ui->listWidget->currentIndex().row();
    if(numderDelet!=0){
    numberList=0;
    if(!sdb.open()) qDebug() << sdb.lastError().text();

     QSqlQuery query= QSqlQuery (sdb);

     query.prepare("delete from List where idPlayer=:idPlay;");
     query.bindValue(":idPlay", numderDelet );

     while (query.next())
        {
         qDebug()<<query.first();
         }
      query.exec();
     query.prepare("delete from NameList where idlist=:idPlay;");
     query.bindValue(":idPlay", numderDelet );

     while (query.next())
        {
         qDebug()<<query.first();
         }
      query.exec();
     delete ui->listWidget->takeItem(ui->listWidget->row(ui->listWidget->currentItem()));
     sdb.close();
     m_playListModel->clear();
     m_playlist->clear();
     Init();
     Player(numberList);
    }else QMessageBox::information(this, "Ошибка", "Нельзя удалить выбранный плейлист!");
}



void Widget::on_listWidget_clicked(const QModelIndex &index)
{

   if(ui->listWidget->currentRow()!=0){
    ui->delete_playlist->setEnabled(true);
    ui->SetNumberPlaylist->setEnabled(true);
   }else ui->SetNumberPlaylist->setEnabled(true);
}
