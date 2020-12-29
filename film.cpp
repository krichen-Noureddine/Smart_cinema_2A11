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
QSqlQueryModel * film::cherchernom(const QString &type)
{
     QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from film where nom like '" + type + "%' ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("genre"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Duree"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date_de_sortie"));


    return model;
}
QSqlQueryModel * film::chercherid(const QString &type)
{
     QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from film where (id like '" + type + "%') ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("genre"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Duree"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date_de_sortie"));


    return model;
}
QSqlQueryModel * film::cherchergenre(const QString &type)
{
     QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from film where genre like '" + type + "%' ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("genre"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Duree"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date_de_sortie"));


    return model;
}

QSqlQueryModel * film::trier_nom()
{
    QSqlQueryModel * model= new QSqlQueryModel();

      model->setQuery("SELECT * FROM film\
                        ORDER BY Nom ");

                      model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
                      model->setHeaderData(1, Qt::Horizontal, QObject::tr("id"));
                      model->setHeaderData(2, Qt::Horizontal, QObject::tr("genre"));
                      model->setHeaderData(3, Qt::Horizontal, QObject::tr("Duree"));
                      model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date_de_sortie"));
      return  model;
}
QSqlQueryModel * film::trier_nom2()
{
    QSqlQueryModel * model= new QSqlQueryModel();

      model->setQuery("SELECT * FROM film\
                        ORDER BY Nom DESC");

                      model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
                      model->setHeaderData(1, Qt::Horizontal, QObject::tr("id"));
                      model->setHeaderData(2, Qt::Horizontal, QObject::tr("genre"));
                      model->setHeaderData(3, Qt::Horizontal, QObject::tr("Duree"));
                      model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date_de_sortie"));
      return  model;
}
QSqlQueryModel * film::trier_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();

      model->setQuery("SELECT * FROM film\
                        ORDER BY id ");

                      model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
                      model->setHeaderData(1, Qt::Horizontal, QObject::tr("id"));
                      model->setHeaderData(2, Qt::Horizontal, QObject::tr("genre"));
                      model->setHeaderData(3, Qt::Horizontal, QObject::tr("Duree"));
                      model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date_de_sortie"));
      return  model;
}
QSqlQueryModel * film::trier_id2()
{
    QSqlQueryModel * model= new QSqlQueryModel();

      model->setQuery("SELECT * FROM film\
                        ORDER BY id DESC");

                      model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
                      model->setHeaderData(1, Qt::Horizontal, QObject::tr("id"));
                      model->setHeaderData(2, Qt::Horizontal, QObject::tr("genre"));
                      model->setHeaderData(3, Qt::Horizontal, QObject::tr("Duree"));
                      model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date_de_sortie"));
      return  model;
}
QSqlQueryModel * film::trier_genre()
{
    QSqlQueryModel * model= new QSqlQueryModel();

      model->setQuery("SELECT * FROM film\
                        ORDER BY genre ");

                      model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
                      model->setHeaderData(1, Qt::Horizontal, QObject::tr("id"));
                      model->setHeaderData(2, Qt::Horizontal, QObject::tr("genre"));
                      model->setHeaderData(3, Qt::Horizontal, QObject::tr("Duree"));
                      model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date_de_sortie"));
      return  model;
}
QSqlQueryModel * film::trier_genre2()
{
    QSqlQueryModel * model= new QSqlQueryModel();

      model->setQuery("SELECT * FROM film\
                        ORDER BY genre DESC");

                      model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
                      model->setHeaderData(1, Qt::Horizontal, QObject::tr("id"));
                      model->setHeaderData(2, Qt::Horizontal, QObject::tr("genre"));
                      model->setHeaderData(3, Qt::Horizontal, QObject::tr("Duree"));
                      model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date_de_sortie"));
      return  model;
}
