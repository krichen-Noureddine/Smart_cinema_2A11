#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "even.h"
#include <QDebug>
#include <QRegularExpression>
#include "connection.h"
#include"film.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{   MRE=QRegExp("^[0-9]+([0-9]*[-._+])*[0-9]");
    ui->setupUi(this);
    ui->tablefilm->setModel(tempfilm.afficherfilm());
   // this->setStyleSheet("background-color: rgb(202,202,202);");



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_4_clicked()
{
 int i =ui->lineEdit_id->text().toInt();
 QString n =ui->lineEdit_nom->text();
 QString p=ui->comboBox->currentText();
 QDate d=ui->dateEdit->date();
 QTime t=ui->timeEdit->time();




 qDebug() << t.toString();
  film f(n,i,p,t.toString(),d);
                 bool verifier =MRE.exactMatch(ui->lineEdit_id->text());
      if ( ui->lineEdit_nom->text()!="" )
      {
              if (!verifier)
              { QMessageBox::warning(nullptr, QObject::tr("Ajouter film"),
                                    QObject::tr("Vérifier id ! .\n"
                                                "click cancel to exit"),
                                     QMessageBox::Cancel);
               }
             else
              {  int i =ui->lineEdit_id->text().toInt();
                  QString n =ui->lineEdit_nom->text();
                  QString p=ui->comboBox->currentText();
                  QDate d=ui->dateEdit->date();
                  QTime t=ui->timeEdit->time();
                  qDebug() << t.toString();
                   film f(n,i,p,t.toString(),d);


               bool test =f.ajouterfilm();
               if (test)
  {
      ui->tablefilm->setModel(tempfilm.afficherfilm());

      QMessageBox::information(nullptr,"Ajout Film","film ajouté");
  }
  else
  {  QMessageBox::warning(nullptr,"Ajout Film","film ajouté");
   }

}

                }

        else
        {
            QMessageBox::warning(nullptr, QObject::tr("Ajouter film"),
                        QObject::tr("Ajout echoué ! Cases vides ! .\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }

    }




void MainWindow::on_pushButton_supprimer_clicked()
{
  int i= ui->lineEdit_supprimer->text().toInt();
  bool test=tempfilm.supprimerfilm(i);
  if (test)
  { ui->tablefilm->setModel(tempfilm.afficherfilm());
   QMessageBox::information(nullptr,"suppression film","film supprimé");
}
  else
   QMessageBox::warning(nullptr,"Ajout Film","film  non supprimé");

}

void MainWindow::on_pushButton_even_clicked()

    {
     int i =ui->lineEdit_id_2->text().toInt();
     QString n =ui->lineEdit_nom_2->text();

     QDateTime d=ui->dateTimeEdit_1->dateTime();
     QDateTime f=ui->dateTimeEdit_2->dateTime();

      even e(n,i,d,f);
      bool test =e.ajoutereven();
      if (test)
      {  QMessageBox::information(nullptr,"evenement Film","evenement ajouté");
      }
      else
      {  QMessageBox::warning(nullptr,"evenement Film","evenement ajouté");
    }
}

void MainWindow::on_lineEdit_nom_returnPressed()
{

}

void MainWindow::on_pushButton_6_clicked()
{

        if (ui->radioButton_3->isChecked())
        {
            QString type= ui->lineEdit_18->text() ;
            ui->tablefilm->setModel(tempfilm.cherchernom(type));

        }

        if (ui->radioButton->isChecked())
        {
            QString type= ui->lineEdit_18->text() ;
            ui->tablefilm->setModel(tempfilm.chercherid(type));

        }

        if (ui->radioButton_2->isChecked())
        {
            QString type= ui->lineEdit_18->text() ;
            ui->tablefilm->setModel(tempfilm.cherchergenre(type));

        }
        if (!(ui->radioButton_3->isChecked())&&!(ui->radioButton_2->isChecked())&&!(ui->radioButton->isChecked()))
               {
            QMessageBox::critical(nullptr, QObject::tr("cherche échoué"),
                                   QObject::tr("\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }


void MainWindow::on_comboBox2_activated(const QString &arg1)
{
    if(arg1=="Nom")
       {
        if (ui->radioButton_7->isChecked())
        {
            ui->tablefilm->setModel(tempfilm.trier_nom());

        }
        if (ui->radioButton_8->isChecked())
        {
            ui->tablefilm->setModel(tempfilm.trier_nom2());

        }
       }
    if(arg1=="id")
       {
        if (ui->radioButton_7->isChecked())
        {
            ui->tablefilm->setModel(tempfilm.trier_id());

        }
        if (ui->radioButton_8->isChecked())
        {
            ui->tablefilm->setModel(tempfilm.trier_id2());

        }
       }
    if(arg1=="genre")
       {
        if (ui->radioButton_7->isChecked())
        {
            ui->tablefilm->setModel(tempfilm.trier_genre());

        }
        if (ui->radioButton_8->isChecked())
        {
            ui->tablefilm->setModel(tempfilm.trier_genre2());

        }
       }

    if (arg1=="Select")
    {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                    QObject::tr("Tu n'as pas choisis   !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}
