#-------------------------------------------------
#
# Project created by QtCreator 2020-11-20T16:21:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testMovetoThread1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    process_a.cpp

HEADERS  += mainwindow.h \
    process_a.h

FORMS    += mainwindow.ui
