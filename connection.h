#ifndef CONNECTION_H
#define CONNECTION_H
#include<QSqlQuery>
#include <QtSql>
#include <QSqlDatabase>
class Connection
{
    QSqlDatabase db;
    QSqlTableModel *tableModel;


public:
    Connection();
    bool createconnection();
    void closeconnection();
};

#endif // CONNECTION_H
