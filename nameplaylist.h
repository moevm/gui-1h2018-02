#ifndef NAMEPLAYLIST_H
#define NAMEPLAYLIST_H

#include <QDialog>
#include "QSqlDatabase"
#include "QSqlQuery"

namespace Ui {
class NamePlayList;
}

class NamePlayList : public QDialog
{
    Q_OBJECT

public:
    explicit NamePlayList(QWidget *parent = 0);
    ~NamePlayList();

    QString getInput() const;

private slots:
    void on_buttonBox_clicked();

private:
    Ui::NamePlayList *ui;
     QString name;

};

#endif // NAMEPLAYLIST_H
