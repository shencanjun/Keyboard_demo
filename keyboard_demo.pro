#-------------------------------------------------
#
# Project created by QtCreator 2013-04-04T23:11:38
#
#-------------------------------------------------

QT       += gui-private widgets

TARGET = keyboard_demo
TEMPLATE = app

CONFIG += c++11

#DEFINES += VIRTUALKEYBOARD_LIBRARY

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/pinyin/ -lgooglepinyin
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/pinyin/ -lgooglepinyind

LIBS += -L$$PWD/pinyin/ -lgooglepinyin

INCLUDEPATH += $$PWD/pinyin
DEPENDPATH += $$PWD/pinyin

SOURCES += \
#    inputcontext.cpp \
    main.cpp \
    googlepinyin.cpp \
    keyboardform.cpp \
    keyeventdispatcher.cpp \
    mainwindow.cpp


HEADERS +=\
    mainwindow.h \
    pinyinime.h \
#    inputcontext.h \
    googlepinyin.h \
    keyboardform.h \
    keyeventdispatcher.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    res.qrc
