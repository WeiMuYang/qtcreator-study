#-------------------------------------------------
#
# Project created by QtCreator 2020-11-04T19:04:38
#
#-------------------------------------------------

QT       += core gui network


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MMJKProTest1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    io_ctrl.cpp \
    do_thr.cpp \
    di_thr.cpp

HEADERS  += mainwindow.h \
    bdaqctrl.h \
    compatibility.h \
    io_ctrl.h \
    do_thr.h \
    di_thr.h

FORMS    += mainwindow.ui

unix: LIBS += -lbiodaq
