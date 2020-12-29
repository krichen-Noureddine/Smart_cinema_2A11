
QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connection.cpp \
    even.cpp \
    film.cpp \
    mailing/mimeattachment.cpp \
    mailing/mimeattachment.cpp \
    mailing/mimecontentformatter.cpp \
    mailing/mimecontentformatter.cpp \
    mailing/mimefile.cpp \
    mailing/mimefile.cpp \
    mailing/mimehtml.cpp \
    mailing/mimehtml.cpp \
    mailing/mimeinlinefile.cpp \
    mailing/mimeinlinefile.cpp \
    mailing/mimemessage.cpp \
    mailing/mimemessage.cpp \
    mailing/mimemultipart.cpp \
    mailing/mimemultipart.cpp \
    mailing/mimepart.cpp \
    mailing/mimepart.cpp \
    mailing/mimetext.cpp \
    mailing/mimetext.cpp \
    mailing/quotedprintable.cpp \
    mailing/quotedprintable.cpp \
    mailing/smtpclient.cpp \
    mailing/smtpclient.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    connection.h \
    even.h \
    film.h \
    mailing/SmtpMime \
    mailing/SmtpMime \
    mailing/mimeattachment.h \
    mailing/mimeattachment.h \
    mailing/mimecontentformatter.h \
    mailing/mimecontentformatter.h \
    mailing/mimefile.h \
    mailing/mimefile.h \
    mailing/mimehtml.h \
    mailing/mimehtml.h \
    mailing/mimeinlinefile.h \
    mailing/mimeinlinefile.h \
    mailing/mimemessage.h \
    mailing/mimemessage.h \
    mailing/mimemultipart.h \
    mailing/mimemultipart.h \
    mailing/mimepart.h \
    mailing/mimepart.h \
    mailing/mimetext.h \
    mailing/mimetext.h \
    mailing/quotedprintable.h \
    mailing/quotedprintable.h \
    mailing/smtpclient.h \
    mailing/smtpclient.h \
    mailing/smtpexports.h \
    mailing/smtpexports.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc
