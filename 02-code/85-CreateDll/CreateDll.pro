#-------------------------------------------------
#
# Project created by QtCreator 2020-09-26T09:27:18
#
#-------------------------------------------------

QT       += core gui

#   TARGET = CreateDll 修改
TARGET = myqtdll
TEMPLATE = lib

DEFINES += CREATEDLL_LIBRARY

SOURCES += my_dll.cpp \
    display_data.cpp \
    function.cpp

HEADERS += my_dll.h\
        createdll_global.h \
    my_dll.h \
    display_data.h \
    function.h


unix {
    target.path = /usr/lib
    INSTALLS += target
}
