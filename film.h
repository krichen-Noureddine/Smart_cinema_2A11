#ifndef FILM_H
#define FILM_H
#include <QString>
#include <QVariant>
#include<QSqlQuery>
#include<QDateEdit>
#include<QDate>
#include<QTimeEdit>
#include<QTime>
#include<QSqlQueryModel>
class film
{
     QString nom;
     int id;
     QString genre;
     QDate date;
     QString duree;

public:
    film();
    film(QString,int,QString,QString,QDate);
         QString get_nom(){return nom;}
         int get_id(){return id;};
         QString get_genre(){return genre;}
         QDate get_date() {return date;}
         QString get_duree(){return duree;}
         bool ajouterfilm();
         bool supprimerfilm(int);
         QSqlQueryModel *afficherfilm();
};

#endif // FILM_H
