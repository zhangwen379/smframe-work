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
    varmsg.cpp \
    varmsgqueue.cpp \
    varstate.cpp \
    varstatemachine.cpp \
    varstate_idle.cpp \
    varstate_pause.cpp \
    varstate_work.cpp \
    variants.cpp \
    makefilepath.cpp

HEADERS += \
    object.h \
    state.h \
    thing.h \
    vardesc.h \
    vardesctable.h \
    variant.h \
    base.h \
    varmsg.h \
    varmsgqueue.h \
    varstate.h \
    varstatemachine.h \
    varstate_idle.h \
    varstate_pause.h \
    varstate_work.h \
    variants.h \
    makefilepath.h
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
