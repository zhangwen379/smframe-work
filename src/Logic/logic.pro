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
    varsm_thread.cpp \
    varsm_thread_ball.cpp \
    varstate_work_ball.cpp \
    varsm_thread_allsystem.cpp \
    varstate_work_allsystem.cpp

HEADERS += logic.h \
    varsm_thread.h \
    varsm_thread_ball.h \
    varstate_work_ball.h \
    varsm_thread_allsystem.h \
    varstate_work_allsystem.h

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
