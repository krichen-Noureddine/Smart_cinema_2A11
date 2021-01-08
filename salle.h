#ifndef SALLE_H
#define SALLE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class salle
{
public:
    salle();
    salle(int,int,QString);
    int get_id();
    int get_capacite();
    QString get_disponibilite();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool rech(int);
    bool modifier(int,QString,int);



    bool trier();
    QSqlQueryModel * Modelid();
    QSqlQueryModel * Modelid_categorie();
    QSqlQueryModel * recherchee(QString,QString,int);
    QSqlQueryModel * TRI(QString,QString,int);
    QSqlQueryModel * afficher_cat(QString ref_ch);
    void statistique(QVector<double>*,QVector<QString>*);
private:
        int id,capacite;
        QString disponibilite;
};

#endif // SALLE_H
