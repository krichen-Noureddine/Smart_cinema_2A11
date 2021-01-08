#ifndef POSTE_H
#define POSTE_H
#include <QString>
#include <QDate>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlDatabase>
#include "connection.h"
#include <QDebug>
#include <QFileDialog>
#include <QtDebug>
#include <QMessageBox>

class poste
{
private:
    int id_poste;
    int nbr_heurs;
    int jours_conges;
    QString salaire;
    QString prime;

public:
    poste(int,int,int,QString,QString);
    QSqlQueryModel * afficher();
    int get_id_poste(){return id_poste;}
    int get_nbr_heurs(){return nbr_heurs;}
    int get_jours_conges(){return jours_conges;}
    QString get_salaire(){return salaire;}
    QString get_prime(){return prime;}

    bool ajouter();
    QSqlQueryModel *chercher_post_id(const QString &aux);
    QSqlQueryModel *chercher_post_nbrh(const QString &aux);
    QSqlQueryModel *chercher_post_slr(const QString &aux);
    void setposte(int,int,int,QString,QString);
    bool supprimer(int i) ;
    bool modifier() ;
    QSqlQueryModel * trie();
    QSqlQueryModel * trie2();
    poste();
};

#endif // POSTE_H
