#-------------------------------------------------
#
# Project created by QtCreator 2022-05-05T08:15:13
#
#-------------------------------------------------

QT       += xml

QT       -= gui

TARGET = base
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    object.cpp \
    state.cpp \
    thing.cpp \
    vardesc.cpp \
    vardesctable.cpp \
    variant.cpp \
    variants.cpp \
    makefilepath.cpp \
    v_msg.cpp \
    v_msgqueue.cpp \
    v_state.cpp \
    vs_idle.cpp \
    vsi_pause.cpp \
    vs_work.cpp \
    v_statemachine.cpp \
    cprecisetime.cpp

HEADERS += \
    object.h \
    state.h \
    thing.h \
    base.h \
    makefilepath.h \
    vs_idle.h \
    vsi_pause.h \
    vs_work.h \
    v_statemachine.h \
    v_msg.h \
    vardesc.h \
    variant.h \
    vardesctable.h \
    variants.h \
    v_msgqueue.h \
    v_state.h \
    cprecisetime.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
#-------------------------------------------------
# 额外添加
#-------------------------------------------------
DESTDIR = ../../lib
INCLUDEPATH += ../../includes
PRECOMPILED_HEADER = base.h
