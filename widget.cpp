#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QDir>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
         PlayList.setFileName("PlayList.txt");
 PlayList.open(QIODevice::ReadWrite|QIODevice::Text);
    ui->setupUi(this);
    // Настройка таблицы плейлиста
    m_playListModel = new QStandardItemModel(this);
    ui->playlistView->setModel(m_playListModel);    // Устанавливаем модель данных в TableView
    // Устанавливаем заголовки таблицы
    m_playListModel->setHorizontalHeaderLabels(QStringList()  << tr("Audio Track")
                                                            << tr("File Path"));

    ui->playlistView->setEditTriggers(QAbstractItemView::NoEditTriggers);   // Отключаем редактирование
        ui->playlistView->hideColumn(1);    // Скрываем колонку, в которой хранится путь к файлу
     ui->playlistView->verticalHeader()->setVisible(false);                  // Скрываем нумерацию строк
     ui->playlistView->setSelectionBehavior(QAbstractItemView::SelectRows);  // Включаем выделение строк
    // Включаем подгонку размера последней видимой колонки к ширине TableView
    ui->playlistView->horizontalHeader()->setStretchLastSection(true);

    m_player = new QMediaPlayer(this);          // Инициализируем плеер
    m_playlist = new QMediaPlaylist(m_player);  // Инициализируем плейлист
         m_player->setPlaylist(m_playlist);          // Устанавливаем плейлист в плеер
 m_player->setVolume(70);                    // Устанавливаем громкость воспроизведения треков
 m_playlist->setPlaybackMode(QMediaPlaylist::Loop);  // Устанавливаем циклический режим проигрывания плейлиста
 Player();
   // подключаем кнопки управления к слотам управления
   // Здесь отметим, что навигация по плейлисту осуществляется именно через плейлист

   connect(ui->btn_play, &QToolButton::clicked, m_player, &QMediaPlayer::play);
    connect(ui->btn_stop, &QToolButton::clicked, m_player, &QMediaPlayer::stop);
    // При даблклике по треку в таблице устанавливаем трек в плейлисте
        connect(ui->playlistView, &QTableView::doubleClicked, [this](const QModelIndex &index){
            m_playlist->setCurrentIndex(index.row());
        });
 }

Widget::~Widget()
{
    delete ui;
    delete m_playListModel;
    delete m_playlist;
    delete m_player;
}


void Widget::on_btn_add_clicked()
{
    // С помощью диалога выбора файлов делаем множественный выбор mp3 файлов
    QStringList files = QFileDialog::getOpenFileNames(this,
                                                      tr("Open files"),
                                                      QString(),
                                                      tr("Audio Files (*.mp3)"));
     QTextStream stream(&PlayList);

    // Далее устанавливаем данные по именам и пути к файлам
    // в плейлист и таблицу отображающую плейлист
    foreach (QString filePath, files) {
        QList<QStandardItem *> items;
        items.append(new QStandardItem(QDir(filePath).dirName()));
        items.append(new QStandardItem(filePath));
        m_playListModel->appendRow(items);
         stream << filePath << "\r\n";
        m_playlist->addMedia(QUrl(filePath));
    }
}
void Widget:: Player(){
    if (PlayList.isOpen()){
        QString line;
        QTextStream stream(&PlayList);//
        while (!stream.atEnd()){
                  line+=stream.readLine()+"\n";
               }
        QStringList lines = line.split( "\n", QString::SkipEmptyParts );


     foreach (QString filePath, lines) {

        QList<QStandardItem *> items;
        items.append(new QStandardItem(QDir(filePath).dirName()));
        items.append(new QStandardItem(filePath));
        m_playListModel->appendRow(items);
        m_playlist->addMedia(QUrl(filePath));
    }
   }
}
