#include "even.h"
#include <QSqlQuery>
even::even()
{

}

even::even(QString n,int i,QDateTime d,QDateTime f )
{nom=n;
id=i;
datedebut=d;
datefin=f;

}
bool even::ajoutereven()
{QSqlQuery query;
    query.prepare("insert into even (nom,id,date_debut,date_fin)"
                  "VALUES (:nom,:id,:datedebut,:datefin)");
   QString r=QString::number(id);
    query.bindValue(":nom",nom);
    query.bindValue(":id",r);
    query.bindValue(":datedebut",datedebut);
    query.bindValue(":datefin",datefin);


    return query.exec();



}
