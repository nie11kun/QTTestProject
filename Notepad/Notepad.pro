QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    notepad.cpp

HEADERS += \
    notepad.h

FORMS += \
    notepad.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


LIBS += -L"C:/Users/Marco Nie/Library/boost_1_72_0/stage/lib/" \
        -l libboost_filesystem-mgw81-mt-x32-1_72.dll

INCLUDEPATH += "C:/Users/Marco Nie/Library/boost_1_72_0"
DEPENDPATH += "C:/Users/Marco Nie/Library/boost_1_72_0"
