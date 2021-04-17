#-------------------------------------------------
#
# Project created by QtCreator 2020-07-31T20:24:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testJsonCPP
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    json/json_reader.cpp \
    json/json_value.cpp \
    json/json_writer.cpp

HEADERS  += mainwindow.h \
    json/autolink.h \
    json/config.h \
    json/features.h \
    json/forwards.h \
    json/json.h \
    json/json_batchallocator.h \
    json/reader.h \
    json/value.h \
    json/writer.h

FORMS    += mainwindow.ui
