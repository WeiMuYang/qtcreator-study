#-------------------------------------------------
#
# Project created by QtCreator 2020-09-02T21:15:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 72-ThreadChangeUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cthread.cpp \
    changestatus.cpp

HEADERS  += mainwindow.h \
    cthread.h \
    changestatus.h

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc
