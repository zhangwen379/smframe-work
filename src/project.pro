TEMPLATE = subdirs

SUBDIRS += $$PWD/base \
           $$PWD/logic \
           $$PWD/gui

logic.depends=base
gui.depends=logic

