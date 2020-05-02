#-------------------------------------------------
#
# Project created by QtCreator 2020-03-04T08:16:14
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Gladiator
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        cards.cpp \
        cardsfrm.cpp \
        datenbank.cpp \
        frmadminpanel.cpp \
        frmhighscore.cpp \
        frmlogin.cpp \
        frmssh.cpp \
        gladiatorgame.cpp \
        gladiatormain.cpp \
        main.cpp \
        frmmain.cpp \
        player.cpp \
        qrightclickbutton.cpp \
        ssh.cpp \
        wip.cpp

HEADERS += \
        cards.h \
        cardsfrm.h \
        datenbank.h \
        frmadminpanel.h \
        frmhighscore.h \
        frmlogin.h \
        frmmain.h \
        frmssh.h \
        gladiatorgame.h \
        gladiatormain.h \
        player.h \
        qrightclickbutton.h \
        ssh.h \
        wip.h

FORMS += \
        cardsfrm.ui \
        frmadminpanel.ui \
        frmhighscore.ui \
        frmlogin.ui \
        frmmain.ui \
        frmssh.ui \
        gladiatormain.ui \
        wip.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
