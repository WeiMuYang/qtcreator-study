#-------------------------------------------------
#
# Project created by QtCreator 2020-08-23T15:35:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 65-ThreadHeapAndStack
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    childthread.cpp

HEADERS  += mainwindow.h \
    childthread.h

FORMS    += mainwindow.ui
