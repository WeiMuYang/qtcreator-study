#-------------------------------------------------
#
# Project created by QtCreator 2020-07-15T20:02:07
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt18demo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    wellsdata.cpp

HEADERS  += mainwindow.h \
    wellsdata.h

FORMS    += mainwindow.ui

DISTFILES +=

RESOURCES += \
    images.qrc
