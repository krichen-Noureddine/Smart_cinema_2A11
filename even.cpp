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
QSqlQueryModel *even::affichereven()
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("select *from even");
    model->setHeaderData(0,Qt::Horizontal,"Nom");
    model->setHeaderData(1,Qt::Horizontal,"Id");
    model->setHeaderData(2,Qt::Horizontal,"datedebut");
    model->setHeaderData(3,Qt::Horizontal,"datefin");


    return model;

}
bool even::modifiereven()
{

    QSqlQuery query;

    query.prepare("UPDATE even SET ID=:id,NOM=:nom,Date_debut=:datedebut, Date_fin=:datefin  WHERE ID=:id") ;
    QString r=QString::number(id);
    query.bindValue(":nom",nom);
    query.bindValue(":id",r);
    query.bindValue(":datedebut",datedebut);
    query.bindValue(":datefin",datefin);

    return    query.exec();
}


bool even::supprimereven(int i)
{QSqlQuery query;
query.prepare("Delete from even where id=:id");
QString r=QString::number(i);
query.bindValue(":id",r);
return query.exec();
}
