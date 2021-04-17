#-------------------------------------------------
#
# Project created by QtCreator 2020-09-26T12:25:00
#
#-------------------------------------------------

TARGET = qtdll
TEMPLATE = lib

DEFINES += CREATEDLL_LIBRARY

SOURCES += createdll.cpp \
    display_data.cpp \
    function.cpp

HEADERS += createdll.h\
        createdll_global.h \
    display_data.h \
    function.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES +=
