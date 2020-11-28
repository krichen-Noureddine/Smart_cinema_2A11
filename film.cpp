#include "film.h"

film::film()
{

}
film::film(QString n,int i,QString g,QString t,QDate d)
{nom=n;
id=i;
genre=g;
date=d;
duree=t;
}
bool film::ajouterfilm()
{QSqlQuery query;
    query.prepare("insert into Film(nom,id,genre,durée,date_de_sortie)"
                  "VALUES (:nom,:id,:genre,:duree,:date)");
   QString r=QString::number(id);
    query.bindValue(":nom",nom);
    query.bindValue(":id",r);
    query.bindValue(":genre",genre);
    query.bindValue(":date",date);
    query.bindValue(":duree",duree);

    return query.exec();



}
bool film::supprimerfilm(int i)
{QSqlQuery query;
    query.prepare("Delete from film where id=:id");
   QString r=QString::number(i);
   query.bindValue(":id",r);
return query.exec();
}
QSqlQueryModel *film::afficherfilm()
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("select *from film");
    model->setHeaderData(0,Qt::Horizontal,"Nom");
    model->setHeaderData(1,Qt::Horizontal,"Id");
    model->setHeaderData(2,Qt::Horizontal,"Genre");
    model->setHeaderData(3,Qt::Horizontal,"Duree");
    model->setHeaderData(4,Qt::Horizontal,"Date_de_sortie");

    return model;

}
