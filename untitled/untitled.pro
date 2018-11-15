#-------------------------------------------------
#
# Project created by QtCreator 2018-09-06T20:16:01
#
#-------------------------------------------------

QT       += core gui widgets script network

TARGET = untitled
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
    file_meteo_io.cpp \
    main.cpp \
    meteo_form.cpp \
    mainwindow.cpp \
    airportsdialog.cpp \
    udpserver.cpp \
    backward.cpp \
    meteo_struct.cpp \
    mainvisual.cpp

HEADERS += \
    meteo_struct.h \
    file_meteo_io.h \
    meteo_form.h \
    ../build-untitled-Desktop_Qt_5_11_1_MSVC2017_64bit-Debug/ui_meteoform.h \
    ../build-untitled-Desktop_Qt_5_11_1_MSVC2017_64bit-Debug/ui_mainwindow.h \
    mainwindow.h \
    airportsdialog.h \
    udpserver.h \
    ../build-untitled-Desktop_Qt_5_11_1_MSVC2017_64bit-Debug/ui_airportsdialog.h \
    backward.h \
    mainvisual.h \
    utilities.h

FORMS += \
    meteoform.ui \
    mainwindow.ui \
    mainwindow.ui \
    airportsdialog.ui \
    backward.ui \
    mainvisual.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
