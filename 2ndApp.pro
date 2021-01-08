QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += printsupport
CONFIG += c++11
QT += core gui charts
QT += core gui network  multimedia multimediawidgets
QT += serialport

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    client.cpp \
    connection.cpp \
    dialog.cpp \
    employe.cpp \
    even.cpp \
    film.cpp \
    historique.cpp \
    main.cpp \
    mainwindow.cpp \
    notification.cpp \
    poste.cpp \
    projection.cpp \
    qcustomplot.cpp \
    salle.cpp \
    smtp.cpp \
    ticket.cpp

HEADERS += \
    arduino.h \
    client.h \
    connection.h \
    dialog.h \
    employe.h \
    even.h \
    film.h \
    historique.h \
    mainwindow.h \
    notification.h \
    poste.h \
    projection.h \
    qcustomplot.h \
    salle.h \
    smtp.h \
    ticket.h

FORMS += \
    dialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc \
    myappico.qrc
   QMAKE_CXXFLAGS += -std=gnu++14
DISTFILES += \
    img/white-cinema-screen-with-audience_38187-89.jpg \
    istockphoto-970785084-170667a.jpg \
    panneau-clap-film-fond-rose-pour-equipement-tournage_9555-779.jpg
