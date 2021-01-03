#include "login.h"
#include "ui_login.h"
#include <QString>
#include "employe.h"
Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_btnconnect_clicked()
{
    QString id = ui->lineutilisateur->text();
    QString mdp = ui->linemdp->text();
    Employe e;
    int res = e.chercher(id);
    if(res == 1){
        // Code si Succes
        if(mdp == e.getmdp()) {
            ui->labmsg->setText("Succes");
            this->done(1);
        }
        // mdp erroné
        else {
            ui->labmsg->setText("Mdp Erroné");
    }
    }
    else {
        //utilisateur n'exite pas
        ui->labmsg->setText("Utilisateur n'exite pas!");
    }
}
