/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QToolButton *btn_add;
    QToolButton *btn_previous;
    QToolButton *btn_stop;
    QToolButton *btn_play;
    QToolButton *btn_pause;
    QToolButton *btn_next;
    QTableView *playlistView;
    QTableView *tableView;
    QTableView *tableView_2;
    QTextEdit *textEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->setEnabled(true);
        Widget->resize(793, 720);
        Widget->setMouseTracking(false);
        Widget->setTabletTracking(false);
        Widget->setAcceptDrops(false);
        QIcon icon;
        icon.addFile(QStringLiteral(":/from.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        Widget->setToolTipDuration(-1);
        Widget->setStyleSheet(QStringLiteral(""));
        btn_add = new QToolButton(Widget);
        btn_add->setObjectName(QStringLiteral("btn_add"));
        btn_add->setGeometry(QRect(20, 30, 51, 51));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/butten_plus.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_add->setIcon(icon1);
        btn_add->setIconSize(QSize(35, 35));
        btn_previous = new QToolButton(Widget);
        btn_previous->setObjectName(QStringLiteral("btn_previous"));
        btn_previous->setGeometry(QRect(100, 30, 51, 51));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/butten3.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_previous->setIcon(icon2);
        btn_previous->setIconSize(QSize(45, 45));
        btn_stop = new QToolButton(Widget);
        btn_stop->setObjectName(QStringLiteral("btn_stop"));
        btn_stop->setGeometry(QRect(160, 30, 51, 51));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/butten2.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_stop->setIcon(icon3);
        btn_stop->setIconSize(QSize(45, 48));
        btn_play = new QToolButton(Widget);
        btn_play->setObjectName(QStringLiteral("btn_play"));
        btn_play->setGeometry(QRect(220, 30, 51, 51));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/butten1.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_play->setIcon(icon4);
        btn_play->setIconSize(QSize(45, 48));
        btn_pause = new QToolButton(Widget);
        btn_pause->setObjectName(QStringLiteral("btn_pause"));
        btn_pause->setGeometry(QRect(280, 30, 51, 51));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/butten5.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_pause->setIcon(icon5);
        btn_pause->setIconSize(QSize(45, 45));
        btn_next = new QToolButton(Widget);
        btn_next->setObjectName(QStringLiteral("btn_next"));
        btn_next->setGeometry(QRect(340, 30, 51, 51));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/butten4.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_next->setIcon(icon6);
        btn_next->setIconSize(QSize(45, 45));
        playlistView = new QTableView(Widget);
        playlistView->setObjectName(QStringLiteral("playlistView"));
        playlistView->setEnabled(true);
        playlistView->setGeometry(QRect(20, 180, 481, 521));
        playlistView->setMouseTracking(false);
        playlistView->setTabletTracking(false);
        playlistView->setAcceptDrops(false);
        playlistView->setToolTipDuration(-1);
        playlistView->setLayoutDirection(Qt::LeftToRight);
        playlistView->setAutoFillBackground(false);
        playlistView->setStyleSheet(QLatin1String("font: italic 14pt \"Vivaldi\";\n"
""));
        playlistView->setAutoScroll(true);
        playlistView->setProperty("showDropIndicator", QVariant(true));
        playlistView->setShowGrid(true);
        playlistView->setWordWrap(true);
        tableView = new QTableView(Widget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(520, 160, 256, 211));
        tableView_2 = new QTableView(Widget);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));
        tableView_2->setGeometry(QRect(520, 390, 256, 281));
        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(540, 200, 211, 61));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "AudioHelga", nullptr));
#ifndef QT_NO_TOOLTIP
        Widget->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        Widget->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        btn_add->setText(QApplication::translate("Widget", "...", nullptr));
        btn_previous->setText(QApplication::translate("Widget", "...", nullptr));
        btn_stop->setText(QApplication::translate("Widget", "...", nullptr));
        btn_play->setText(QApplication::translate("Widget", "...", nullptr));
        btn_pause->setText(QApplication::translate("Widget", "...", nullptr));
        btn_next->setText(QApplication::translate("Widget", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
