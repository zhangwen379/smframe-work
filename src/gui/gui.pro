#-------------------------------------------------
#
# Project created by QtCreator 2022-05-06T16:38:32
#
#-------------------------------------------------

QT       += core gui
QT       += xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qtw_varlist.cpp \
    qw_ball.cpp \
    cmopenglwidget.cpp

HEADERS  += mainwindow.h \
    gui.h \
    qtw_varlist.h \
    qw_ball.h \
    cmopenglwidget.h

FORMS    += mainwindow.ui


win32: LIBS += -L../../lib/ -lbase#$$PWD/

INCLUDEPATH += ../../#$$PWD/
DEPENDPATH += ../../#$$PWD/

win32:!win32-g++: PRE_TARGETDEPS += ../../lib/base.lib#$$PWD/
else:win32-g++: PRE_TARGETDEPS += ../../lib/libbase.a#$$PWD/


win32: LIBS += -L$$PWD/../../lib/ -llogic

INCLUDEPATH += $$PWD/../../
DEPENDPATH += $$PWD/../../

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../lib/logic.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/../../lib/liblogic.a



#-------------------------------------------------
# 额外添加
#-------------------------------------------------
DESTDIR = ../../bin
INCLUDEPATH += ../base
INCLUDEPATH += ../logic
INCLUDEPATH += ../../includes
INCLUDEPATH += ../../includes/vld_include
PRECOMPILED_HEADER = gui.h


win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../lib/vld_lib/ -lvld

INCLUDEPATH += $$PWD/../../lib/vld_lib
DEPENDPATH += $$PWD/../../lib/vld_lib
