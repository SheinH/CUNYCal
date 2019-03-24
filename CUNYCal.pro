#-------------------------------------------------
#
# Project created by QtCreator 2019-03-18T23:27:02
#
#-------------------------------------------------

QT       += core gui multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CUNYCal
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

CONFIG += c++17

SOURCES += \
        main.cpp \
        win1.cpp \
    Course.cpp \
    CourseScanner.cpp \
    automode.cpp \
    manualmode.cpp

HEADERS += \
        win1.h \
    Course.h \
    CourseScanner.h \
    automode.h \
    manualmode.h

FORMS += \
        win1.ui \
    automode.ui \
    manualmode.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    res.qrc
