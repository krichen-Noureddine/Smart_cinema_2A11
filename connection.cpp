#include "connection.h"
#include <QDebug>
#include <QSqlQuery>

connection::connection()
{
}


bool connection::createconnect()
{ bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("app");//inserer le nom de la source de données ODBC
db.setUserName("nouri");//inserer nom de l'utilisateur
db.setPassword("0000");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
   return  test;
}

bool connection::loginconnection(QString username, QString password){
    bool connected = true;

    QSqlQuery query(QSqlDatabase::database("app"));
    query.prepare(QString("SELECT * FROM EMPLOYE WHERE IDEMPLOYE =:username AND MDP =:password"));
    query.bindValue(":username",username);
    query.bindValue(":password",password);
    query.first();
    if(!query.exec()){qDebug() <<"failed exec";}
    else{
        while(query.next()){
            QString usernameFromDB=query.value(0).toString();
            QString passwordFromDB=query.value(1).toString();
            if ((usernameFromDB == username )&& (passwordFromDB == password))connected = true;
            }
    }
    return connected;
}

