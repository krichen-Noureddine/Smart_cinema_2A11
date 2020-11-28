#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "even.h"
#include <QDebug>
#include <QRegularExpression>
#include "connection.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{   MRE=QRegExp("^[0-9]+([0-9]*[-._+])*[0-9]");
    ui->setupUi(this);
    ui->tablefilm->setModel(tempfilm.afficherfilm());



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
