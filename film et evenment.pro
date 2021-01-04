QT       += core gui sql printsupport network

QT += serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG +=console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    connection.cpp \
    dialog.cpp \
    even.cpp \
    film.cpp \
    historique.cpp \
    main.cpp \
    mainwindow.cpp \
    smtp.cpp

HEADERS += \
    arduino.h \
    connection.h \
    dialog.h \
    even.h \
    film.h \
    historique.h \
    mainwindow.h \
    smtp.h

FORMS += \
    dialog.ui \
    mainwindow.ui
RC_ICONS = myappico.ico
QMAKE_CXXFLAGS += -std=gnu++14

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc \
    image.qrc \
    res.qrc

DISTFILES += \
    ../../Nouveau dossier (4)/------------/projetcpp/res/print.png \
    historique.txt \
    print.png
