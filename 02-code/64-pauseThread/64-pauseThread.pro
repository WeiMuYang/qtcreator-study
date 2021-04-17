#-------------------------------------------------
#
# Project created by QtCreator 2020-08-22T15:50:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 64-pauseThread
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    childthread.cpp

HEADERS  += mainwindow.h \
    childthread.h

FORMS    += mainwindow.ui
