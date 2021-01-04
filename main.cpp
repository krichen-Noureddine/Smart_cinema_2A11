#include "mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    Connection c;
    bool app=c.createconnection();
    MainWindow w;
    if (app)
    { w.show();
        QMessageBox::information(nullptr,QObject::tr("database is open"),
    QObject::tr("connection successful.\n""click cancel to exit"),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("database is not open"),
                               QObject::tr("connection failed\n"
                                           "click cancel to exit"),QMessageBox::Cancel);

    return a.exec();
}
