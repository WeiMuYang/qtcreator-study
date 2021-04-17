#-------------------------------------------------
#
# Project created by QtCreator 2020-09-26T09:49:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 85-UseDll
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h
FORMS    += mainwindow.ui



LIBS += -L$$PWD/myDll/lib -lmyqtdll
 #LIBS += -L$$PWD/myDll/ -lmyqtdlld

INCLUDEPATH += $$PWD/myDll/include
DEPENDPATH += $$PWD/myDll
