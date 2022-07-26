#-------------------------------------------------
#
# Project created by QtCreator 2022-05-05T14:46:50
#
#-------------------------------------------------

QT       += xml

QT       -= gui

TARGET = Logic
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    vsm_thread.cpp \
    vsmt_allsystem.cpp \
    vsmt_ball.cpp \
    vsw_allsystem.cpp \
    vsw_ball.cpp

HEADERS += logic.h \
    vsm_thread.h \
    vsmt_allsystem.h \
    vsmt_ball.h \
    vsw_allsystem.h \
    vsw_ball.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

#-------------------------------------------------
# 额外添加
#-------------------------------------------------
DESTDIR = ../../lib
INCLUDEPATH += ../base
INCLUDEPATH += ../../includes
PRECOMPILED_HEADER = logic.h
