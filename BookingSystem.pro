#-------------------------------------------------
#
# Project created by QtCreator 2017-11-26T14:11:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BookingSystem
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    hairdresser.cpp \
    hairdresserregister.cpp \
    customers.cpp \
    customerregister.cpp \
    treatment.cpp \
    haircut.cpp \
    colortreatment.cpp \
    booking.cpp \
    bookingregister.cpp \
    login.cpp \
    newuser.cpp \
    loginuser.cpp \
    booktime.cpp \
    changeinformation.cpp \
    removeBooking.cpp

HEADERS += \
        mainwindow.h \
    hairdresser.h \
    hairdresserregister.h \
    customers.h \
    customerregister.h \
    treatment.h \
    haircut.h \
    colortreatment.h \
    booking.h \
    bookingregister.h \
    login.h \
    newuser.h \
    loginuser.h \
    booktime.h \
    changeinformation.h \
    removeBooking.h

FORMS += \
        mainwindow.ui \
    login.ui \
    newuser.ui \
    loginuser.ui \
    booktime.ui \
    changeinformation.ui \
    removeBooking.ui
