#-------------------------------------------------
#
# Project created by QtCreator 2020-08-01T21:46:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 14-TestJsonCpp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    jsoncpp.cpp

HEADERS  += mainwindow.h \
    json/json.h \
    json/json-forwards.h

FORMS    += mainwindow.ui
