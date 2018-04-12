#-------------------------------------------------
#
# Project created by QtCreator 2017-11-07T19:50:38
#
#-------------------------------------------------

QT       += core gui
QT += widgets serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = ADS1298_Monitor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    channelallwindow.cpp \
    irrfilter.cpp \
    waveletfilter.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    channelallwindow.h \
    iirfilter.h \
    waveletfilter.h

FORMS    += mainwindow.ui \
    channelallwindow.ui
