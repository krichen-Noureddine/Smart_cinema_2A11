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
           bool modifier();
         bool supprimerfilm(int);
         QSqlQueryModel *afficherfilm();
         QSqlQueryModel * cherchernom(const QString &);
         QSqlQueryModel * chercherid(const QString &);
         QSqlQueryModel * cherchergenre(const QString &);

         QSqlQueryModel * trier_nom();
         QSqlQueryModel * trier_id();
         QSqlQueryModel * trier_genre();

         QSqlQueryModel * trier_nom2();
         QSqlQueryModel * trier_id2();
         QSqlQueryModel * trier_genre2();
};

#endif // FILM_H
