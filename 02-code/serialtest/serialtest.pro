QT += core
QT -= gui

QT       += serialport

CONFIG += c++11

TARGET = serialtest
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    useserial.cpp

HEADERS += \
    useserial.h
