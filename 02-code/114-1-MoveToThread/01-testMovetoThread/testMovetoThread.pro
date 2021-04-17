#-------------------------------------------------
#
# Project created by QtCreator 2020-11-20T16:21:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testMovetoThread
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    process_a.cpp \
    process_b.cpp

HEADERS  += mainwindow.h \
    process_a.h \
    process_b.h

FORMS    += mainwindow.ui
