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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QPushButton *SetNumberPlaylist;
    QPushButton *delete_playlist;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QTableView *playlistView;
    QHBoxLayout *horizontalLayout;
    QToolButton *btn_previous;
    QToolButton *btn_stop;
    QToolButton *btn_play;
    QToolButton *btn_pause;
    QToolButton *btn_next;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *btn_add;
    QLabel *label;
    QPushButton *NewPlayList;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->setEnabled(true);
        Widget->resize(778, 647);
        Widget->setMouseTracking(false);
        Widget->setTabletTracking(false);
        Widget->setAcceptDrops(false);
        QIcon icon;
        icon.addFile(QStringLiteral(":/from.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        Widget->setToolTipDuration(-1);
        Widget->setStyleSheet(QStringLiteral(""));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(480, 300, 261, 271));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(layoutWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);

        SetNumberPlaylist = new QPushButton(layoutWidget);
        SetNumberPlaylist->setObjectName(QStringLiteral("SetNumberPlaylist"));

        verticalLayout->addWidget(SetNumberPlaylist);

        delete_playlist = new QPushButton(layoutWidget);
        delete_playlist->setObjectName(QStringLiteral("delete_playlist"));

        verticalLayout->addWidget(delete_playlist);

        layoutWidget1 = new QWidget(Widget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(40, 130, 401, 471));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        playlistView = new QTableView(layoutWidget1);
        playlistView->setObjectName(QStringLiteral("playlistView"));
        playlistView->setEnabled(true);
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

        verticalLayout_2->addWidget(playlistView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btn_previous = new QToolButton(layoutWidget1);
        btn_previous->setObjectName(QStringLiteral("btn_previous"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/butten3.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_previous->setIcon(icon1);
        btn_previous->setIconSize(QSize(45, 45));

        horizontalLayout->addWidget(btn_previous);

        btn_stop = new QToolButton(layoutWidget1);
        btn_stop->setObjectName(QStringLiteral("btn_stop"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/butten2.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_stop->setIcon(icon2);
        btn_stop->setIconSize(QSize(45, 48));

        horizontalLayout->addWidget(btn_stop);

        btn_play = new QToolButton(layoutWidget1);
        btn_play->setObjectName(QStringLiteral("btn_play"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/butten1.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_play->setIcon(icon3);
        btn_play->setIconSize(QSize(45, 48));

        horizontalLayout->addWidget(btn_play);

        btn_pause = new QToolButton(layoutWidget1);
        btn_pause->setObjectName(QStringLiteral("btn_pause"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/butten5.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_pause->setIcon(icon4);
        btn_pause->setIconSize(QSize(45, 45));

        horizontalLayout->addWidget(btn_pause);

        btn_next = new QToolButton(layoutWidget1);
        btn_next->setObjectName(QStringLiteral("btn_next"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/butten4.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        btn_next->setIcon(icon5);
        btn_next->setIconSize(QSize(45, 45));

        horizontalLayout->addWidget(btn_next);


        verticalLayout_2->addLayout(horizontalLayout);

        layoutWidget2 = new QWidget(Widget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(510, 140, 211, 51));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btn_add = new QToolButton(layoutWidget2);
        btn_add->setObjectName(QStringLiteral("btn_add"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/butten_plus.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_add->setIcon(icon6);
        btn_add->setIconSize(QSize(35, 35));

        horizontalLayout_2->addWidget(btn_add);

        label = new QLabel(layoutWidget2);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        NewPlayList = new QPushButton(Widget);
        NewPlayList->setObjectName(QStringLiteral("NewPlayList"));
        NewPlayList->setGeometry(QRect(510, 220, 211, 51));
        QFont font;
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        NewPlayList->setFont(font);

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
        SetNumberPlaylist->setText(QApplication::translate("Widget", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\277\320\273\320\265\320\271\320\273\320\270\321\201\321\202", nullptr));
        delete_playlist->setText(QApplication::translate("Widget", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\277\320\273\320\265\320\271\320\273\320\270\321\201\321\202", nullptr));
        btn_previous->setText(QApplication::translate("Widget", "...", nullptr));
        btn_stop->setText(QApplication::translate("Widget", "...", nullptr));
        btn_play->setText(QApplication::translate("Widget", "...", nullptr));
        btn_pause->setText(QApplication::translate("Widget", "...", nullptr));
        btn_next->setText(QApplication::translate("Widget", "...", nullptr));
        btn_add->setText(QApplication::translate("Widget", ".", nullptr));
        label->setText(QApplication::translate("Widget", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; font-style:italic;\">\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\260\321\203\320\264\320\270\320\276\320\267\320\260\320\277\320\270\321\201\321\214</span></p></body></html>", nullptr));
        NewPlayList->setText(QApplication::translate("Widget", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\275\320\276\320\262\321\213\320\271 \320\277\320\273\320\265\320\271\320\273\320\270\321\201\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
