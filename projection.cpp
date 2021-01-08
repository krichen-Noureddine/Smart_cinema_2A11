#include "projection.h"

projection::projection()
{

}
projection::projection(int id,QString date,QString heure,int id_salle,QString qualite)
{
  this->heure=heure;
  this->id=id;
  this->date=date;
  this->id_salle=id_salle;
  this->qualite=qualite;


}

int projection::get_id(){return  id;}
QString projection::get_date(){return date;}
QString projection::get_heure(){return heure;}
int projection::get_id_salle(){return id_salle;}
QString projection::get_qualite(){return qualite;}

QSqlQueryModel * projection::Modelid()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery();
    query->prepare("select id from projection");
    query->exec();
    model->setQuery(*query);
    return model;
}

bool projection::ajouter(){
    QSqlQuery query;

    query.prepare("INSERT INTO projection (id, date1, heure, id_salle, qualite) VALUES (:id, :date, :heure, :id_salle, :qualite )");
    query.bindValue(":id", id);
    query.bindValue(":date", date);
    query.bindValue(":heure", heure);
    query.bindValue(":id_salle", id_salle);
    query.bindValue(":qualite", qualite);


    return query.exec();
}
QSqlQueryModel * projection::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from projection");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("date"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("heure"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("id_salle"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("qualite"));


    return model;
}
bool projection::supprimer(int ref_ch)
{
QSqlQuery query;

query.prepare("Delete from projection where id = :ref ");
query.bindValue(":ref", ref_ch);
return    query.exec();
}
bool projection::rech(int x){
    QSqlQuery query;
    query.prepare("select * from projection where id = :reference;");
    query.bindValue(":reference", x);
    return query.exec();
}
bool projection::modifier(int f,QString a,QString b,int c,QString d){
    QSqlQuery query;
    QString yep=QString::number(f);
    query.prepare("UPDATE projection set date1=:date ,heure=:heure ,id_salle=:id_salle , qualite=:qualite   where id ='"+yep+"'");
    query.bindValue(":id",f);
    query.bindValue(":date", a);
    query.bindValue(":heure", b);
    query.bindValue(":id_salle", c);
    query.bindValue(":qualite", d);
    return query.exec();
}

QSqlQueryModel * projection::Modelid_salle()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery();
    query->prepare("select id from salle");
    query->exec();
    model->setQuery(*query);
    return model;
}
