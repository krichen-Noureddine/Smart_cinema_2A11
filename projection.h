#ifndef PROJECTION_H
#define PROJECTION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class projection
{
public:
    projection();
    projection(int,QString,QString,int,QString);
    int get_id();
    int get_id_salle();
    QString get_date();
    QString get_heure();
    QString get_qualite();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool rech(int);
    bool modifier(int,QString,QString,int,QString);
    QSqlQueryModel * Modelid();
    QSqlQueryModel * Modelid_salle();
    void statistique(QVector<double>*,QVector<QString>*);
private:
    int id,id_salle;
    QString date,heure,qualite;
};

#endif // PROJECTION_H
