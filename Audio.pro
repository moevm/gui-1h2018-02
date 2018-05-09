

#-------------------------------------------------
#
# Project created by QtCreator 2018-03-15T11:25:56
#
#-------------------------------------------------

QT       += core gui multimedia
QT += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Audio
TEMPLATE = app



SOURCES +=\
        widget.cpp \
    main.cpp \
    nameplaylist.cpp

HEADERS  += widget.h \
    nameplaylist.h

FORMS    += widget.ui \
    widget.ui \
    nameplaylist.ui

RESOURCES += \
    buttons.qrc



