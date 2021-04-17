#-------------------------------------------------
#
# Project created by QtCreator 2020-07-31T21:50:00
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testJsonCPPDist
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    jsoncpp.cpp \
    processjson.cpp

HEADERS  += mainwindow.h \
    json.h \
    processjson.h

FORMS    += mainwindow.ui
