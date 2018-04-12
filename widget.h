
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
#include "database.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    void Player();
    void Init();

    ~Widget();

private slots:
    void on_btn_add_clicked();              // Слот для обработки добавления треков через диалоговое окно
    void Delete_one();
private:

    QFile PlayList;
    Ui::Widget *ui;
    QStandardItemModel  *m_playListModel;   // Модель данных плейлиста для отображения
    QMediaPlayer        *m_player;          // Проигрыватель треков
    QMediaPlaylist      *m_playlist;        // Плейлиста проигрывателя
    QSqlDatabase sdb;

protected:
  void paintEvent(QPaintEvent*) {
    QPainter p(this);
    p.drawPixmap(0, 0, QPixmap("from.jpg"));
  }
};

#endif // WIDGET_H

