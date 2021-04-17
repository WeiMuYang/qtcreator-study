#-------------------------------------------------
#
# Project created by QtCreator 2020-07-25T14:29:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qobjcom
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    showmsg.cpp \
    ioctrl.cpp

HEADERS  += widget.h \
    showmsg.h \
    ioctrl.h

FORMS    += widget.ui
