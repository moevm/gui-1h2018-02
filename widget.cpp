#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QDir>
#include <QPalette>
#include <QByteArray>
#include <QSqlRecord>
#include <QSqlError>
#include <QTableView>
#include <QTableWidgetItem>
#include <QVariant>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
   //Подключаем базу данных
    sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName("C:\\Users\\dns\\Desktop\\Qt\\SQLiteDatabaseBrowserPortable\\Data\\audio.sqlite");

 ui->setupUi(this);
 // Настройка таблицы плейлиста
 m_playListModel = new QStandardItemModel(this);
 m_player = new QMediaPlayer(this);          // Инициализируем плеер
 m_playlist = new QMediaPlaylist(m_player);  // Инициализируем плейлист

 ui->playlistView->setModel(m_playListModel);    // Устанавливаем модель данных в TableView
 // Устанавливаем заголовки таблицы
 m_playListModel->setHorizontalHeaderLabels(QStringList()<< tr("Audio Track") << tr("File Path"));

 ui->playlistView->setEditTriggers(QAbstractItemView::NoEditTriggers);   // Отключаем редактирование
 ui->playlistView->hideColumn(1);    // Скрываем колонку, в которой хранится путь к файлу
 ui->playlistView->verticalHeader()->setVisible(false);                  // Скрываем нумерацию строк
 ui->playlistView->setSelectionBehavior(QAbstractItemView::SelectRows);  // Включаем выделение строк
 // Включаем подгонку размера последней видимой колонки к ширине TableView
 ui->playlistView->horizontalHeader()->setStretchLastSection(true);

 m_player->setPlaylist(m_playlist);          // Устанавливаем плейлист в плеер
 m_player->setVolume(70);                    // Устанавливаем громкость воспроизведения треков
 m_playlist->setPlaybackMode(QMediaPlaylist::Loop);  // Устанавливаем циклический режим проигрывания плейлиста
 Player();

 // подключаем кнопки управления к слотам управления
   // Здесь отметим, что навигация по плейлисту осуществляется именно через плейлист
 connect(ui->btn_play, &QToolButton::clicked, m_player, &QMediaPlayer::play);
  connect(ui->btn_stop, &QToolButton::clicked, m_player, &QMediaPlayer::stop);
  connect(ui->btn_previous, &QToolButton::clicked, m_playlist, &QMediaPlaylist::previous);
   connect(ui->btn_next, &QToolButton::clicked, m_playlist, &QMediaPlaylist::next);
    connect(ui->btn_pause, &QToolButton::clicked, m_player, &QMediaPlayer::pause);
  //connect(ui->btn_stop, &QToolButton::clicked, Player(), &QMediaPlayer::stop);
  // При даблклике по треку в таблице устанавливаем трек в плейлисте
      connect(ui->playlistView, &QTableView::clicked, [this](const QModelIndex &index){
          m_playlist->setCurrentIndex(index.row());
      });
      connect(ui->playlistView, &QTableView::clicked, [this](const QModelIndex &index){
          m_playlist->setCurrentIndex(index.row());
      });
     QObject:: connect(ui->playlistView, SIGNAL(doubleClicked(QModelIndex)), SLOT(Delete_one()));



}
void Widget:: Delete_one(){
    int row = ui->playlistView->currentIndex().row();
    QVariant myData; //Сюда положим данные из ячейки
    QModelIndex myIndex;
    myIndex = ui->playlistView->model()->index( row, 1, QModelIndex()); // row, column это интересующая вас ячейка
    myData = ui->playlistView->model()->data( myIndex, Qt::DisplayRole); // role это интересующая вас роль, например Qt::DisplayRole
    //данные в QVariant приводите к чему хотите и обрабатывайте
   QString names=myData.toString();
    qDebug()<< myData.toString();

   if(!sdb.open()) qDebug() << sdb.lastError().text();

   QSqlQuery query= QSqlQuery (sdb);

     query.prepare("delete from List where name=:names;");
     query.bindValue(":names", names );
     //names=query.exec();
     while (query.next())
        {
         qDebug()<<query.first();
         }
     qDebug()<< query.exec();
     sdb.close();
      m_playListModel->clear();
      ui->playlistView->model()->removeRow(row);
      m_playlist->clear();
      Init();
      Player();
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
    ui->playlistView->setSelectionBehavior(QAbstractItemView::SelectRows);  // Включаем выделение строк
    // Включаем подгонку размера последней видимой колонки к ширине TableView
    ui->playlistView->horizontalHeader()->setStretchLastSection(true);

  // m_player = new QMediaPlayer(this);          // Инициализируем плеер
  //m_playlist = new QMediaPlaylist(m_player);  // Инициализируем плейлист
    m_player->setPlaylist(m_playlist);          // Устанавливаем плейлист в плеер
    m_player->setVolume(70);                    // Устанавливаем громкость воспроизведения треков
    m_playlist->setPlaybackMode(QMediaPlaylist::Loop);  // Устанавливаем циклический режим проигрывания плейлиста

}
void Widget:: Player(){

    if(!sdb.open()) qDebug() << sdb.lastError().text();

    QSqlQuery query= QSqlQuery (sdb);

      if (!query.exec("select * from List")) {
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

      //Butten();
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
     m_playListModel->appendRow(items);
     m_playlist->addMedia(QUrl(filePath));

          //Осуществляем запрос
     if(!sdb.open()) qDebug() << sdb.lastError().text();
     QSqlQuery query= QSqlQuery (sdb);
     query.prepare("insert into List('name') values(:stream);");//добавление данных
     query.bindValue(":stream", streamm);
     if(!query.exec()){
            qDebug() << "error insert into ";
            qDebug() << query.lastError().text();
     }

     sdb.close();

 }
}
