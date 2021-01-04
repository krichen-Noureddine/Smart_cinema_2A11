#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "even.h"
#include <QDebug>
#include <QRegularExpression>
#include "connection.h"
#include <QtPrintSupport>
#include <QPrintDialog>
#include <dialog.h>
#include<historique.h>
#include <QTextDocument>
#include <QTextBrowser>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{   MRE=QRegExp("^[0-9]+([0-9]*[-._+])*[0-9]");
    ui->setupUi(this);
    mSystemTrayIcon = new QSystemTrayIcon(this);
    mSystemTrayIcon->setIcon(QIcon(":/myappico.png"));
         mSystemTrayIcon->setVisible(true);
    ui->tablefilm->setModel(tempfilm.afficherfilm());
       ui->lineEdit_nom->setPlaceholderText("Nom ...");
       ui->lineEdit_id->setPlaceholderText("Id ...");
       ui->tableeven->setModel(tempeven.affichereven());
       ui->lineEdit_impr->setPlaceholderText("Taper l'id du film a imprimer");
            ui->lineEdit_impr_2->setPlaceholderText("Taper l'id event a imprimer");

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

historique.save("Genre :"+ui->comboBox->currentText(),"Nom :"+ui->lineEdit_nom->text());


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
mSystemTrayIcon->showMessage(tr("Notification"),
                        tr("Film ajouté"));
}
else
{  QMessageBox::warning(nullptr,"Ajout Film","film ajouté");
    mSystemTrayIcon->showMessage(tr("Notification"),
                            tr("Ajout echoué"));
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
      bool verifier =MRE.exactMatch(ui->lineEdit_id_2->text());
if ( ui->lineEdit_nom_2->text()!="" )
{
   if (!verifier)
   { QMessageBox::warning(nullptr, QObject::tr("Ajouter even"),
                         QObject::tr("Vérifier id ! .\n"
                                     "click cancel to exit"),
                          QMessageBox::Cancel);
    }
  else
   {  int i =ui->lineEdit_id_2->text().toInt();
       QString n =ui->lineEdit_nom_2->text();
       QDateTime d=ui->dateTimeEdit_1->dateTime();
       QDateTime f=ui->dateTimeEdit_2->dateTime();
        even e(n,i,d,f);


    bool test =e.ajoutereven();
    if (test)
{
ui->tableeven->setModel(tempeven.affichereven());

QMessageBox::information(nullptr,"event ajouté","event ajouté");
}
else
{  QMessageBox::warning(nullptr,"Ajout event","event ajouté");
}

}

     }

else
{
 QMessageBox::warning(nullptr, QObject::tr("Ajouter event"),
             QObject::tr("Ajout echoué ! Cases vides ! .\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);
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





void MainWindow::on_pushButton_email_clicked()
{
    QItemSelectionModel *select = ui->tablefilm->selectionModel();


        QString nom=select->selectedRows(1).value(0).data().toString();



       QDialog *d=new Dialog(nom,this);
        d->show();
        d->exec();
}



void MainWindow::on_pushButton_impr_clicked()
{
    QString num1 = ui->lineEdit_impr->text();
        int num = ui->lineEdit_impr->text().toInt();

        QSqlQuery query;

        QString nom;
        int id;
        QString genre;
        QDate date;
        QString duree;

        if(num1!=""){

        query.prepare("select * from film where ID =:id");
        query.bindValue(":id", num);
        if (query.exec())
        {

            while (query.next()) {


                 id= query.value(1).toInt();
                 genre=query.value(2).toString();

                 nom= query.value(0).toString();

                 date= query.value(4).toDate();

                 duree=query.value(3).toString();


             }
        }
              QPrinter printer(QPrinter::HighResolution);
                  printer.setPageSize(QPrinter::A4);

                 QPrintDialog *dialog = new QPrintDialog(&printer);
                  if (dialog->exec() == QDialog::Accepted)
                  {               QPainter painter(&printer);
                                  painter.begin(&printer);


                                  QFont f;
                                      f.setPointSize(20);
                                      f.setBold(true);
                                      painter.setFont(f);
                                   painter.drawText(1800, 500, "nouveau film");
                                   f.setPointSize(15);
                                   f.setBold(true);
                                   painter.setFont(f);

                                   painter.drawText(100, 2000, "duree:");
                                   painter.drawText(1500, 2000,duree);
                                   painter.drawText(100, 1600, "genre:");
                                   painter.drawText(1500, 1600,genre);

                                   painter.drawText(100, 1300, "Nom:");
                                   painter.drawText(1500, 1300,nom);





                                  painter.end();

                  }
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Imprimer dossier"),
                        QObject::tr("Erreur !.\n"
                                    "Veuillez selectionner un id de patient à imprimer .\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}
void MainWindow::ref()
{
    ui->tablefilm->setModel(tempfilm.afficherfilm());
       ui->tableeven->setModel(tempeven.affichereven());
}

void MainWindow::on_pushButton_2_clicked()
{
    int i =ui->lineEdit_id->text().toInt();
       QString n =ui->lineEdit_nom->text();
       QString p=ui->comboBox->currentText();
       QDate d=ui->dateEdit->date();
       QTime t=ui->timeEdit->time();

       qDebug() << t.toString();
        film f(n,i,p,t.toString(),d);
    f.modifier();
    bool test=f.modifier();
    if(test)
    {
ref();
        QMessageBox::information(nullptr, QObject::tr("Modifier un film"),
                    QObject::tr("film modifié.\n"
                                "Cliquez sur Ok pour continuer."), QMessageBox::Ok);
    }
    else

       QMessageBox::critical(nullptr, QObject::tr("Modifier un film"),
                   QObject::tr("Erreur!\n"
                               "Erreur de modification du film.\n Veuillez réessayer."), QMessageBox::Ok);
}
void MainWindow::on_pushButton_modif_clicked()
{
    int i =ui->lineEdit_id_2->text().toInt();
           QString n =ui->lineEdit_nom_2->text();
           QDateTime d=ui->dateTimeEdit_1->dateTime();
           QDateTime f=ui->dateTimeEdit_2->dateTime();
            even e(n,i,d,f);
    e.modifiereven();
    bool test=e.modifiereven();
    if(test)
    {
ref();
        QMessageBox::information(nullptr, QObject::tr("Modifier un event"),
                    QObject::tr("event modifié.\n"
                                "Cliquez sur Ok pour continuer."), QMessageBox::Ok);
    }
    else

       QMessageBox::critical(nullptr, QObject::tr("Modifier un event"),
                   QObject::tr("Erreur!\n"
                               "Erreur de modification du event.\n Veuillez réessayer."), QMessageBox::Ok);
}

void MainWindow::on_pushButton_supprimer_2_clicked()
{
    int i= ui->lineEdit_supprimer_2->text().toInt();
    bool test=tempeven.supprimereven(i);
    ui->tableeven->setModel(tempeven.affichereven());
    if (test)
    { ui->tableeven->setModel(tempeven.affichereven());
     QMessageBox::information(nullptr,"suppression event","event supprimé");
  }
    else
     QMessageBox::warning(nullptr,"Ajout event","event  non supprimé");

}

void MainWindow::on_web_clicked()
{
    QString link="http://www.google.com";
           QDesktopServices::openUrl(QUrl(link));
}
