#-------------------------------------------------
#
# Project created by QtCreator 2020-08-23T20:07:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 69-QTimerAndThread
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cthread.cpp

HEADERS  += mainwindow.h \
    cthread.h

FORMS    += mainwindow.ui
