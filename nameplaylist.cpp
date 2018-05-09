#include "nameplaylist.h"
#include "ui_nameplaylist.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlRecord>
#include <QSqlError>

NamePlayList::NamePlayList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NamePlayList)
{
    ui->setupUi(this);

}

NamePlayList::~NamePlayList()
{
    delete ui;
}

void NamePlayList::on_buttonBox_clicked()
{
     name= ui->namelist->text();
    if(!name.isEmpty()){
        QMessageBox::information(this, "Успешно!", "Сохранено");


    }
    else QMessageBox::information(this, "Ошибка", "Неправильный ввод!");
}

QString NamePlayList:: getInput() const{

    return name;
}
