
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStandardItemModel>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QPainter>
#include <QFile>
#include <QSqlTableModel>
#include "QSqlDatabase"
#include "QSqlQuery"
/* Подключаем заголовочный файл для работы с информацией, которая помещена в базу данных */

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    void Player(int number);
    void Init();

    ~Widget();

private slots:
    void on_btn_add_clicked();              // Слот для обработки добавления треков через диалоговое окно
    void Delete_one();




    void on_NewPlayList_clicked();

    void on_SetNumberPlaylist_clicked();

    void on_btn_next_clicked();

    void on_btn_previous_clicked();

    void on_delete_playlist_clicked();

    void on_listWidget_clicked(const QModelIndex &index);


private:

    QFile PlayList;
    Ui::Widget *ui;
    QStandardItemModel  *m_playListModel;   // Модель данных плейлиста для отображения
    QMediaPlayer        *m_player;          // Проигрыватель треков
    QMediaPlaylist      *m_playlist;        // Плейлиста проигрывателя
    QSqlDatabase sdb;
    int numberList=0;

protected:
  void paintEvent(QPaintEvent*) {
    QPainter p(this);
    p.drawPixmap(0, 0, QPixmap("from.jpg"));
  }
};

#endif // WIDGET_H

