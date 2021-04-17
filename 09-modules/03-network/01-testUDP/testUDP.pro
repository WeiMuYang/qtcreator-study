#-------------------------------------------------
#
# Project created by QtCreator 2020-07-29T21:03:04
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testUDP
TEMPLATE = app


SOURCES += main.cpp\
    create_frame.cpp \
    main_window.cpp

HEADERS  += \
    create_frame.h \
    main_window.h

FORMS    += mainwindow.ui
