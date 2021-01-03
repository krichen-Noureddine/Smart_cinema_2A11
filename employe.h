#ifndef EMPLOYE_H
#define EMPLOYE_H
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


class Employe
{
private:
    QString idEmploye;
    QString nom;
    QString DateNaiss;
    int NumTel;
    QString Adress;
    QString Mdp;
    int id_poste;

public:
    Employe(QString,QString,QString,int,QString,QString,int);
    QSqlQueryModel * afficher();
    QString get_idEmploye(){return idEmploye;}
    QString get_nom(){return nom;}
    QString get_DateNaiss(){return DateNaiss;}
    int get_Numtel(){return NumTel;}
    QString get_adress(){return Adress;}
    int get_id_poste(){return id_poste;}
    bool ajouter();
    QSqlQueryModel *chercher_emp_id(const QString &aux);
    QSqlQueryModel *chercher_emp_nom(const QString &aux);
    QSqlQueryModel *chercher_emp_mdp(const QString &aux);
    void setEmploye(QString,QString,QString,int,QString,QString,int);
    bool supprimer(int i) ;
    bool modifier() ;
    QSqlQueryModel * trie();
    QSqlQueryModel * trie2();

    Employe();
};

#endif // EMPLOYE_H
