#-------------------------------------------------
#
# Project created by QtCreator 2020-06-15T22:30:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = TestPlot
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    ui_mainwindow.h

FORMS    += mainwindow.ui
