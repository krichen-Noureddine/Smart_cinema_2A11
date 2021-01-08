#include "salle.h"

salle::salle()
{

}
salle::salle(int id,int capacite,QString disponibilite)
{

  this->id=id;
  this->disponibilite=disponibilite;
  this->capacite=capacite;


}

int salle::get_id(){return  id;}
QString salle::get_disponibilite(){return disponibilite;}
int salle::get_capacite(){return capacite;}
QSqlQueryModel * salle::Modelid()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery();
    query->prepare("select id from salle");
    query->exec();
    model->setQuery(*query);
    return model;
}

bool salle::ajouter(){
    QSqlQuery query;
    query.prepare("INSERT INTO salle (id, disponibilite,capacite) VALUES (:id, :disponibilite, :capacite)");
    query.bindValue(":id", id);
    query.bindValue(":disponibilite", disponibilite);
    query.bindValue(":capacite", capacite);
    return query.exec();
}
QSqlQueryModel * salle::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from salle");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("disponibilite"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("capacite"));
    return model;
}
bool salle::supprimer(int ref_ch)
{
QSqlQuery query;

query.prepare("Delete from salle where id = :ref ");
query.bindValue(":ref", ref_ch);
return    query.exec();
}
bool salle::rech(int x){
    QSqlQuery query;
    query.prepare("select * from salle where id = :reference;");
    query.bindValue(":reference", x);
    return query.exec();
}
bool salle::modifier(int a,QString b,int c){
    QSqlQuery query;
    QString yep=QString::number(a);
    query.prepare("UPDATE salle set disponibilite=:disponibilite ,capacite=:capacite  where id ='"+yep+"'");
    query.bindValue(":id",a);
    query.bindValue(":disponibilite", b);
    query.bindValue(":capacite", c);
    return query.exec();
}
QSqlQueryModel * salle:: TRI(QString champ,QString valeur,int etat1)
{
    QSqlQueryModel * model=new QSqlQueryModel();

    QSqlQuery query;
    if(etat1==0)
   { if(valeur=="id"){
            query.prepare("SELECT * FROM salle  order by id");}
        else if(valeur=="disponibilite"){
                    query.prepare("SELECT * FROM salle  order by disponibilite");}
        else if(valeur=="capacite"){
                    query.prepare("SELECT * FROM salle  order by capacite");}


    }
    else if(etat1==1)  { if(valeur=="id"){
            query.prepare("SELECT * FROM salle  order by id");}
        else if(valeur=="disponibilite"){
                    query.prepare("SELECT * FROM salle  order by disponibilite desc ");}
        else if(valeur=="capacite"){
                    query.prepare("SELECT * FROM salle  order by capacite desc ");}

      }
    valeur="%"+valeur+"%";
    query.bindValue(":valeur",valeur);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("disponibilite"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("capacite"));
    return model;
}


QSqlQueryModel * salle:: recherchee(QString champ,QString valeur,int etat1)
{
    QSqlQueryModel * model=new QSqlQueryModel();

    QSqlQuery query;
    if(etat1==0)
   { query.prepare("SELECT * FROM salle WHERE ("+champ+" LIKE :valeur) order by id");}
    else if(etat1==1)  { query.prepare("SELECT * FROM salle WHERE ("+champ+" LIKE :valeur) order by id desc");}
    valeur="%"+valeur+"%";
    query.bindValue(":valeur",valeur);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("disponibilite"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("capacite"));
    return model;
}
void salle::statistique(QVector<double>* ticks,QVector<QString> *labels)
{   QSqlQuery q;
    int i=0;
    q.exec("select id from salle");
    while (q.next()) {
        QString refer = q.value(0).toString();
        i++;
        *ticks<<i;
        *labels <<refer;
}
}
