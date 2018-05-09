/********************************************************************************
** Form generated from reading UI file 'nameplaylist.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAMEPLAYLIST_H
#define UI_NAMEPLAYLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NamePlayList
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *nameplist;
    QLineEdit *namelist;

    void setupUi(QDialog *NamePlayList)
    {
        if (NamePlayList->objectName().isEmpty())
            NamePlayList->setObjectName(QStringLiteral("NamePlayList"));
        NamePlayList->resize(345, 234);
        buttonBox = new QDialogButtonBox(NamePlayList);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(80, 160, 191, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(NamePlayList);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(80, 50, 191, 91));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        nameplist = new QLabel(widget);
        nameplist->setObjectName(QStringLiteral("nameplist"));

        verticalLayout->addWidget(nameplist);

        namelist = new QLineEdit(widget);
        namelist->setObjectName(QStringLiteral("namelist"));

        verticalLayout->addWidget(namelist);


        retranslateUi(NamePlayList);
        QObject::connect(buttonBox, SIGNAL(accepted()), NamePlayList, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NamePlayList, SLOT(reject()));

        QMetaObject::connectSlotsByName(NamePlayList);
    } // setupUi

    void retranslateUi(QDialog *NamePlayList)
    {
        NamePlayList->setWindowTitle(QApplication::translate("NamePlayList", "Dialog", nullptr));
        nameplist->setText(QApplication::translate("NamePlayList", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\277\320\273\320\265\320\271\320\273\320\270\321\201\321\202\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NamePlayList: public Ui_NamePlayList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAMEPLAYLIST_H
