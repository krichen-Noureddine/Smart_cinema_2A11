QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += printsupport
CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connection.cpp \
    employe.cpp \
    main.cpp \
    mainwindow.cpp \
    poste.cpp

HEADERS += \
    connection.h \
    employe.h \
    mainwindow.h \
    poste.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc

DISTFILES += \
    img/white-cinema-screen-with-audience_38187-89.jpg
