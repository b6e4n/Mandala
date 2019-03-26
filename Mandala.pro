#-------------------------------------------------
#
# Project created by QtCreator 2019-03-12T11:54:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Mandala
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    paintingwidget.cpp

HEADERS  += MainWindow.h \
    paintingwidget.h

FORMS    += \
    mainwindow.ui

CONFIG += c++11
