#include "connection.h"

Connection::Connection()
{}
bool Connection::createconnection()
{
    db = QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("app");
    db.setUserName("nouri");
    db.setPassword("0000");
    if (db.open())test=true;
    return test;

}
void Connection::closeconnection(){db.close();}
