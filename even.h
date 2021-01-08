#ifndef EVEN_H
#define EVEN_H
#include<QString>
#include<QDateTimeEdit>
#include<QSqlQueryModel>
class even
{
    QString nom;
    int id;
    QDateTime datedebut;
    QDateTime datefin;



public:
    even();
    even(QString,int,QDateTime,QDateTime);
         QString get_nom(){return nom;}
         int get_id(){return id;};
         QDateTime get_datedebut(){return datedebut;}
         QDateTime get_datefin() {return datefin;}

         bool ajoutereven();
          bool modifiereven();
         bool supprimereven(int);
         QSqlQueryModel *affichereven();

};

#endif // EVEN_H
