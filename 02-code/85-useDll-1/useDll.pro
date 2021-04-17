#-------------------------------------------------
#
# Project created by QtCreator 2020-09-26T12:43:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = useDll
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui




LIBS += -L$$PWD/MyDll/lib/ -lqtdll
INCLUDEPATH += $$PWD/MyDll/include
DEPENDPATH += $$PWD/MyDll/include
