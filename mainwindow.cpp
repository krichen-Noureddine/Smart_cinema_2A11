#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include "connection.h"
#include <QDebug>
#include <QSqlTableModel>
#include "poste.h"
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QtPrintSupport>
#include <QUrl>
#include <QRegularExpression>
#include <dialog.h>
#include "smtp.h"
#include <historique.h>
#include <QMessageBox>
#include<QMessageBox>
#include <QComboBox>
#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QUrl>
#include <QPrinter>
#include <QPrintDialog>
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include"QSortFilterProxyModel"
#include<QUrl>
#include "historique.h"
#include<QTextDocument>
#include<QTextBrowser>
QT_CHARTS_USE_NAMESPACE
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->tableemploye->setModel(tempemploye.afficher());
    MRE=QRegExp("^[0-9]+([0-9]*[-._+])*[0-9]");

        mSystemTrayIcon = new QSystemTrayIcon(this);
        mSystemTrayIcon->setIcon(QIcon(":/myappico.png"));
             mSystemTrayIcon->setVisible(true);
        ui->tablefilm_affichefilm->setModel(tempfilm.afficherfilm());
           ui->lineEdit_nomfilm->setPlaceholderText("Nom ...");
           ui->lineEdit_idfilm->setPlaceholderText("Id ...");
           ui->tableeven_2->setModel(tempeven.affichereven());
           ui->lineEdit_imprimerfilm->setPlaceholderText("Taper l'id du film a imprimer");
                ui->lineEdit_imprimereven->setPlaceholderText("Taper l'id event a imprimer");

                ui->tableView_4->setModel(tmprec.afficher());//refresh
                        ui->id_c->setModel(tmprec.Modelid_salle());
                        ui->id_cat_m->setModel(tmprec.Modelid_salle());
                        ui->id_m->setModel(tmprec.Modelid());
                        ui->id_s->setModel(tmprec.Modelid());
                        ui->date->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]")));
                        ui->heure->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]")));
                        ui->qualite->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]")));
                        ui->date_m->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]")));
                        ui->heure_m->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]")));
                        ui->qualite_m->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]")));
                        ui->id->setValidator( new QIntValidator(0, 100, this) );
                        ui->id_c->setValidator( new QIntValidator(0, 100, this) );
                        ui->id_m->setValidator( new QIntValidator(0, 100, this) );
                        ui->id_cat_m->setValidator( new QIntValidator(0, 100, this) );
                        ui->tableView->setModel(tmprec.afficher());
                        ui->id_m->setModel(tmprec.Modelid());
                        ui->id_s->setModel(tmprec.Modelid());
                        ui->id->setValidator( new QIntValidator(0, 100, this) );
                        ui->tableView->setModel(tmprec.afficher());
                        ui->id_m->setModel(tmprec.Modelid());
                        ui->id_s->setModel(tmprec.Modelid());
                        ui->id->setValidator( new QIntValidator(0, 100, this) );
                        ui->capacite->setValidator( new QIntValidator(0, 100, this) );
                        ui->capacite_m->setValidator( new QIntValidator(0, 100, this) );


    //controle de saisie employe
        ui->id_line->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{8}")));
        ui->line_nom->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
        ui->line_datenaissance->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{8}")));
      //  ui->line_tel->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
        ui->line_adresse->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{20}")));
       // ui->line_mdp->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]")));
        ui->line_id_poste->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{8}")));
    //controle de saisie poste
        ui->ID_LINE->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{8}")));
      //  ui->line_nbheures->setValidator(new QRegExpValidator(QRegExp("[0-9]{4}")));
       // ui->linejourconges->setValidator(new QRegExpValidator(QRegExp("[0-9]{4}")));
        ui->line_salaire->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{8}")));
        ui->line_prime->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{20}")));


        ui->ID_LINE->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{8}")));
        ui->PAS_LINE->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{20}")));
refresh();
}
void MainWindow::refresh(){
    ui->Ticket_affichage->setModel(tmp_Ticket.afficher());
    ui->Client_affichage->setModel(tmp_Client.afficher());
    ui->comboBox_idc->setModel(tmp_Client.afficher());
    ui->comboBox_idc1->setModel(tmp_Client.afficher());
    ui->rcpt->setModel(tmp_Client.afficherMail());

    ui->Client_affichage_2->setModel(tmp_Client.afficher());
    ui->Ticket_affichage1->setModel(tmp_Ticket.afficher());



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::login()
{
    if (cn.loginconnection(ui->ID_LINE->text(), ui->PAS_LINE->text()))
    {
        ui->stackedWidget->setCurrentIndex(1);
    } else
    {
        qDebug()<< "non";
    }
}

void MainWindow::on_login_button_clicked()
{
    bool test=false;

        if(ui->ID_LINE->text().isEmpty())
        {ui->ID_LINE->setStyleSheet("border: 1px solid red");

        }
        else {
        ui->ID_LINE->setStyleSheet("border: 1px solid blue");
        }

        if(ui->PAS_LINE->text().isEmpty())
        {ui->PAS_LINE->setStyleSheet("border: 1px solid red");

        }
        else {
        ui->PAS_LINE->setStyleSheet("border: 1px solid blue");
        }

        if(ui->ID_LINE->text().isEmpty()||ui->ID_LINE->text().isEmpty())
        { test=true;
           QMessageBox::warning(this,"we deliver","Veuillez remplir les champs obligatoires marqués en rouge");
        }
        if(test==false)
        {QString id=ui->ID_LINE->text();
        QString mdp=ui->PAS_LINE->text();
    if(id=="1" && mdp=="1")
        ui->stackedWidget->setCurrentIndex(1); // thezek l page num n
    else
       { QMessageBox::warning(this,"we deliver","Veuillez vérifier votre mot de passe ou votre identifiant");}
        }

 //   ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_ajouter_button_clicked()
{
    QString idEmploye = ui->id_line->text();
    QString nom = ui->line_nom->text();
    QString DateNaiss = ui->line_datenaissance->text();
    int NumTel = ui->line_tel->text().toInt();
    QString Adress = ui->line_mdp->text();
    QString Mdp = ui->line_id_poste->text();
    int id_poste = ui->line_id_poste->text().toInt();

    Employe E(idEmploye,nom,DateNaiss,NumTel,Adress,Mdp,id_poste);
    bool test =E.ajouter();
    if (test)

    {
        ui->tableemploye->setModel(tempemploye.afficher());
        QMessageBox::information(nullptr, QObject::tr("ajout employe"),
                                 QObject::tr("employe ajouté :"), QMessageBox::Cancel);
    }

}



void MainWindow::on_SUPPRIMER8BUTTON_clicked()
{
    int idEmploye = ui->lineEdit_2->text().toInt();
     bool test = tempemploye.supprimer(idEmploye);
     if (test)
      {
         ui->tableemploye->setModel(tempemploye.afficher());
       QMessageBox::information(nullptr, QObject::tr(" suppression employe "),
                              QObject::tr("employe supprimé :"), QMessageBox::Cancel);
      }
}

void MainWindow::on_pushButton_3_clicked()
{
    close();
}

void MainWindow::on_pushButton_recherche_clicked()
{
    {
        Employe p;
        QString text;

        if (ui->radioButton_ID->isChecked()==true)
       {
       text=ui->lineEdit_rechercher->text();
         if(text == "")
         {
             ui->tableemploye->setModel(p.afficher());
         }

         else
         {
             ui->tableemploye->setModel(p.chercher_emp_id(text));
         }
        }


       if(ui->radioButton_nom->isChecked()==true)
        {
            text=ui->lineEdit_rechercher->text();
                 if(text == "")

                 {
                     ui->tableemploye->setModel(p.afficher());

                 }

                 else

                 {
                     ui->tableemploye->setModel(p.chercher_emp_nom(text));
                 }

        }

         else if     (ui->radioButton_mdp->isChecked()==true)
         {

             text=ui->lineEdit_rechercher->text();
                  if(text == "")

                  {
                      ui->tableemploye->setModel(p.afficher());
                  }

                  else

                  {
                      ui->tableemploye->setModel(p.chercher_emp_mdp(text));
                  }
         }
    }
}

void MainWindow::on_tri_button_clicked()
{
    Employe p;
           /*QString critere=ui->cb_historique->currentText();*/
               QString mode;
               // if (ui->rb_asc_historique->isChecked()==true)
           {
                    ui->tableemploye->setModel(p.trie());


           }
               /* else if(ui->rb_desc_historique->isChecked()==true)

                    ui->tableemploye->setModel(p.trie2());*/
    }


void MainWindow::on_modifier_button_clicked()
{
    if (ui->modifier_button->isChecked())
          {
              ui->modifier_button->setDisabled(true);
              ui->modifier_button->setText("Modifiable");
              QSqlTableModel *tableModel= new QSqlTableModel();
              tableModel->setTable("EMPLOYE");
              tableModel->select();
              ui->tableemploye->setModel(tableModel);
          }
          else
          {
              ui->modifier_button->setText("Modifier");
              ui->tableemploye->setModel(tempemploye.afficher());

          }
}
void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}
void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_ajouter_button_2_clicked()
{
    int id_poste = ui->line_idposte->text().toInt();
    int nbr_heurs = ui->line_nbheures->text().toInt();
    int jours_conges = ui->linejourconges->text().toInt();
    QString salaire = ui->line_salaire->text();
    QString prime = ui->line_prime->text();

    poste p(id_poste,nbr_heurs,jours_conges,salaire,prime);
    bool test =p.ajouter();
    if (test)

    {
        ui->tablepostee->setModel(tempposte.afficher());
        QMessageBox::information(nullptr, QObject::tr("ajout poste"),
                                 QObject::tr("employe poste :"), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    close();
}

void MainWindow::on_modifier_button_2_clicked()
{
    if (ui->modifier_button_2->isChecked())
          {
              ui->modifier_button_2->setDisabled(true);
              ui->modifier_button_2->setText("Modifiable");
              QSqlTableModel *tableModel= new QSqlTableModel();
              tableModel->setTable("POSTEE");
              tableModel->select();
              ui->tablepostee->setModel(tableModel);
          }
          else
          {
              ui->modifier_button_2->setText("Modifier");
              ui->tablepostee->setModel(tempposte.afficher());

          }
}

void MainWindow::on_pushButton_rechercherfilm_clicked()
{
    {
        poste p;
        QString text;

        if (ui->radioButton_ID_2->isChecked()==true)
       {
       text=ui->lineEdit_rechercher_2->text();
         if(text == "")
         {
             ui->tablepostee->setModel(p.afficher());
         }

         else
         {
             ui->tablepostee->setModel(p.chercher_post_id(text));
         }
        }


       if(ui->radioButton_nom_2->isChecked()==true)
        {
            text=ui->lineEdit_rechercher_2->text();
                 if(text == "")

                 {
                     ui->tablepostee->setModel(p.afficher());

                 }

                 else

                 {
                     ui->tablepostee->setModel(p.chercher_post_slr(text));
                 }

        }

         else if     (ui->radioButton_mdp_2->isChecked()==true)
         {

             text=ui->lineEdit_rechercher_2->text();
                  if(text == "")

                  {
                      ui->tablepostee->setModel(p.afficher());
                  }

                  else

                  {
                      ui->tablepostee->setModel(p.chercher_post_nbrh(text));
                  }
         }
    }
}

void MainWindow::on_SUPPRIMER8BUTTON_2_clicked()
{
    int id_poste = ui->line_id_supp->text().toInt();
     bool test = tempposte.supprimer(id_poste);
     if (test)
      {
         ui->tablepostee->setModel(tempposte.afficher());
       QMessageBox::information(nullptr, QObject::tr(" suppression poste "),
                              QObject::tr("poste supprimé :"), QMessageBox::Cancel);
      }
}

void MainWindow::on_tri_button_2_clicked()
{
    poste g;
           /*QString critere=ui->cb_historique->currentText();*/
               QString mode;
                if (ui->radioButto_h_asc->isChecked()==true)
           {
                    ui->tablepostee->setModel(g.trie());


           }
                else if(ui->radioButton_des->isChecked()==true)

                    ui->tablepostee->setModel(g.trie2());

}




void MainWindow::on_retour_button_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_retour_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_exporter_button_clicked()
{
    QString strStream;
            QTextStream out(&strStream);



            const int rowCount = ui->tableemploye->model()->rowCount();
            const int columnCount = ui->tableemploye->model()->columnCount();

            out <<  "<html>\n"
                "<head>\n"

                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                <<  QString("<title>%60 les postes</title>\n").arg("poste")
                <<  "</head>\n"
                "<body bgcolor=#ffffff link=#5000A0>\n"
                "<table border=1 cellspacing=0 cellpadding=2>\n";
            out << "<thead><tr bgcolor=#f0f0f0>";
            for (int column = 0; column < columnCount; column++)
                if (! ui->tableemploye->isColumnHidden(column))
                    out << QString("<th>%1</th>").arg(ui->tableemploye->model()->headerData(column, Qt::Horizontal).toString());
            out << "</tr></thead>\n";

            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tableemploye->isColumnHidden(column)) {
                        QString data = ui->tableemploye->model()->data(ui->tableemploye->model()->index(row, column)).toString().simplified();
                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                    }
                }
                out << "</tr>\n";
            }
            out <<  "</table>\n"
                "</body>\n"
                "</html>\n";

            QTextDocument *document = new QTextDocument();
            document->setHtml(strStream);

            QPrinter printer;

            QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
            if (dialog->exec() == QDialog::Accepted) {
                document->print(&printer);
            }

            delete document;
}

void MainWindow::on_exporter_button_2_clicked()
{
    QString strStream;
            QTextStream out(&strStream);



            const int rowCount = ui->tablepostee->model()->rowCount();
            const int columnCount = ui->tablepostee->model()->columnCount();

            out <<  "<html>\n"
                "<head>\n"

                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                <<  QString("<title>%60 les postes</title>\n").arg("poste")
                <<  "</head>\n"
                "<body bgcolor=#ffffff link=#5000A0>\n"
                "<table border=1 cellspacing=0 cellpadding=2>\n";
            out << "<thead><tr bgcolor=#f0f0f0>";
            for (int column = 0; column < columnCount; column++)
                if (! ui->tablepostee->isColumnHidden(column))
                    out << QString("<th>%1</th>").arg(ui->tablepostee->model()->headerData(column, Qt::Horizontal).toString());
            out << "</tr></thead>\n";

            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tablepostee->isColumnHidden(column)) {
                        QString data = ui->tablepostee->model()->data(ui->tablepostee->model()->index(row, column)).toString().simplified();
                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                    }
                }
                out << "</tr>\n";
            }
            out <<  "</table>\n"
                "</body>\n"
                "</html>\n";

            QTextDocument *document = new QTextDocument();
            document->setHtml(strStream);

            QPrinter printer;

            QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
            if (dialog->exec() == QDialog::Accepted) {
                document->print(&printer);
            }

            delete document;
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}









void MainWindow::on_pushButton_ajouterfilm_clicked()
{
 int i =ui->lineEdit_idfilm->text().toInt();
 QString n =ui->lineEdit_nomfilm->text();
 QString p=ui->comboBox_genrefilm->currentText();
 QDate d=ui->dateEdit_datefilm->date();
 QTime t=ui->timeEdit_dureefilm->time();
 qDebug() << t.toString();

historique.save("Genre :"+ui->comboBox_genrefilm->currentText(),"Nom :"+ui->lineEdit_nomfilm->text());


  film f(n,i,p,t.toString(),d);
  bool verifier =MRE.exactMatch(ui->lineEdit_idfilm->text());
if ( ui->lineEdit_nomfilm->text()!="" )
{
if (!verifier)
{ QMessageBox::warning(nullptr, QObject::tr("Ajouter film"),
                     QObject::tr("Vérifier id ! .\n"
                                 "click cancel to exit"),
                      QMessageBox::Cancel);
}
else
{  int i =ui->lineEdit_idfilm->text().toInt();
   QString n =ui->lineEdit_nomfilm->text();
   QString p=ui->comboBox_genrefilm->currentText();
   QDate d=ui->dateEdit_datefilm->date();
   QTime t=ui->timeEdit_dureefilm->time();
   qDebug() << t.toString();
    film f(n,i,p,t.toString(),d);


bool test =f.ajouterfilm();
if (test)
{

ui->tablefilm_affichefilm->setModel(tempfilm.afficherfilm());
musicAdd.setMedia(QUrl("C:/Users/Utilisateur/Desktop/Nouveau dossier (11)/2ndApp1/ajout succe.mp3"));

musicAdd.play();
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




void MainWindow::on_pushButton_supprimerfilm_clicked()
{
  int i= ui->lineEdit_supprimer_film->text().toInt();
  bool test=tempfilm.supprimerfilm(i);
  if (test)
  { ui->tablefilm_affichefilm->setModel(tempfilm.afficherfilm());
   QMessageBox::information(nullptr,"suppression film","film supprimé");
   musicAdd.setMedia(QUrl("C:/Users/Utilisateur/Desktop/Nouveau dossier (11)/2ndApp1/supp succ.mp3"));

       musicAdd.play();
}
  else
   QMessageBox::warning(nullptr,"Ajout Film","film  non supprimé");

}

void MainWindow::on_pushButton_ajoutereven_clicked()

    {
     int i =ui->lineEdit_ideven->text().toInt();
     QString n =ui->lineEdit_nomeven->text();

     QDateTime d=ui->dateTimeEdit_datedebuteven->dateTime();
     QDateTime f=ui->dateTimeEdit_datefineven->dateTime();

      even e(n,i,d,f);
      bool verifier =MRE.exactMatch(ui->lineEdit_ideven->text());
if ( ui->lineEdit_nomeven->text()!="" )
{
   if (!verifier)
   { QMessageBox::warning(nullptr, QObject::tr("Ajouter even"),
                         QObject::tr("Vérifier id ! .\n"
                                     "click cancel to exit"),
                          QMessageBox::Cancel);
    }
  else
   {  int i =ui->lineEdit_ideven->text().toInt();
       QString n =ui->lineEdit_nomeven->text();
       QDateTime d=ui->dateTimeEdit_datedebuteven->dateTime();
       QDateTime f=ui->dateTimeEdit_datefineven->dateTime();
        even e(n,i,d,f);


    bool test =e.ajoutereven();
    if (test)
{
ui->tableeven_2->setModel(tempeven.affichereven());

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
void MainWindow::on_pushButton_rechercherfilme_clicked()
{

        if (ui->radioButton_nomfilm->isChecked())
        {
            QString type= ui->lineEdit_rechercherfilm->text() ;
            ui->tablefilm_affichefilm->setModel(tempfilm.cherchernom(type));

        }

        if (ui->radioButton_idfilm->isChecked())
        {
            QString type= ui->lineEdit_rechercherfilm->text() ;
            ui->tablefilm_affichefilm->setModel(tempfilm.chercherid(type));

        }

        if (ui->radioButton_genrefilm->isChecked())
        {
            QString type= ui->lineEdit_rechercherfilm->text() ;
            ui->tablefilm_affichefilm->setModel(tempfilm.cherchergenre(type));

        }
        if (!(ui->radioButton_genrefilm->isChecked())&&!(ui->radioButton_idfilm->isChecked())&&!(ui->radioButton_nomfilm->isChecked()))
               {
            QMessageBox::critical(nullptr, QObject::tr("cherche échoué"),
                                   QObject::tr("\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }


void MainWindow::on_comboBox_trifilm_activated(const QString &arg1)
{
    if(arg1=="Nom")
       {
        if (ui->radioButton_trifilm1->isChecked())
        {
            ui->tablefilm_affichefilm->setModel(tempfilm.trier_nom());

        }
        if (ui->radioButton_trifilm2->isChecked())
        {
            ui->tablefilm_affichefilm->setModel(tempfilm.trier_nom2());

        }
       }
    if(arg1=="id")
       {
        if (ui->radioButton_trifilm1->isChecked())
        {
            ui->tablefilm_affichefilm->setModel(tempfilm.trier_id());

        }
        if (ui->radioButton_trifilm1->isChecked())
        {
            ui->tablefilm_affichefilm->setModel(tempfilm.trier_id2());

        }
       }
    if(arg1=="genre")
       {
        if (ui->radioButton_trifilm1->isChecked())
        {
            ui->tablefilm_affichefilm->setModel(tempfilm.trier_genre());

        }
        if (ui->radioButton_trifilm2->isChecked())
        {
            ui->tablefilm_affichefilm->setModel(tempfilm.trier_genre2());

        }
       }

    if (arg1=="Select")
    {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                    QObject::tr("Tu n'as pas choisis   !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}





// void MainWindow::on_pushButton_email_clicked()
//{
//    QItemSelectionModel *select = ui->tablefilm->selectionModel();


//        QString nom=select->selectedRows(1).value(0).data().toString();



//       QDialog *d=new Dialog(nom,this);
//        d->show();
//        d->exec();
//}



void MainWindow::on_pushButton_imprimerfilm_clicked()
{
    QString num1 = ui->lineEdit_imprimerfilm->text();
        int num = ui->lineEdit_imprimerfilm->text().toInt();

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
    ui->tablefilm_affichefilm->setModel(tempfilm.afficherfilm());
       ui->tableeven_2->setModel(tempeven.affichereven());
}

void MainWindow::on_pushButton_modifierfilm_clicked()
{
    int i =ui->lineEdit_idfilm->text().toInt();
       QString n =ui->lineEdit_nomfilm->text();
       QString p=ui->comboBox_genrefilm->currentText();
       QDate d=ui->dateEdit_datefilm->date();
       QTime t=ui->timeEdit_dureefilm->time();

       qDebug() << t.toString();
        film f(n,i,p,t.toString(),d);
    f.modifier();
    bool test=f.modifier();
    if(test)
    {
ref();


musicAdd.setMedia(QUrl("C:/Users/Utilisateur/Desktop/Nouveau dossier (11)/2ndApp1/modif succ.mp3"));
musicAdd.play();
mSystemTrayIcon->showMessage(tr("Notification"),
                        tr("Film modifé"));
        QMessageBox::information(nullptr, QObject::tr("Modifier un film"),
                    QObject::tr("film modifié.\n"
                                "Cliquez sur Ok pour continuer."), QMessageBox::Ok);
    }
    else

       QMessageBox::critical(nullptr, QObject::tr("Modifier un film"),
                   QObject::tr("Erreur!\n"
                               "Erreur de modification du film.\n Veuillez réessayer."), QMessageBox::Ok);
}
void MainWindow::on_pushButton_modifiereven_clicked()
{
    int i =ui->lineEdit_ideven->text().toInt();
           QString n =ui->lineEdit_nomeven->text();
           QDateTime d=ui->dateTimeEdit_datedebuteven->dateTime();
           QDateTime f=ui->dateTimeEdit_datefineven->dateTime();
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

void MainWindow::on_pushButton_supprimereven_clicked()
{
    int i= ui->lineEdit_supprimereven->text().toInt();
    bool test=tempeven.supprimereven(i);
    ui->tableeven_2->setModel(tempeven.affichereven());
    if (test)
    { ui->tableeven_2->setModel(tempeven.affichereven());
     QMessageBox::information(nullptr,"suppression event","event supprimé");
  }
    else
     QMessageBox::warning(nullptr,"Ajout event","event  non supprimé");

}











//Crud Tickets
void MainWindow::on_pb_ajouter_clicked()
{
    QString id= ui->lineEdit_id->text();
    QString idc=ui->comboBox_idc->currentText();

    int prix= ui->lineEdit_prix->text().toInt();
    QDate datee = ui->dateEdit->date();
    Ticket t(id,idc,prix,datee);



    if (ui->lineEdit_id->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP IDENTIFIANT!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }

    else if (ui->lineEdit_prix->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP PRIX!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }
    else{



        bool test=t.ajouter();
        if(test)
        {
            refresh();
            musicAdd.setMedia(QUrl("C:/Users/Utilisateur/Desktop/Nouveau dossier (11)/2ndApp1/ajout succe.mp3"));

            musicAdd.play();
            N.notification_ajoutTicket();
            musicAdd.play();
            QMessageBox::information(nullptr, QObject::tr("Ajouter un Ticket"),
                                     QObject::tr("Ticket ajouté.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Ajouter un Ticket"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);


    }}


void MainWindow::on_pb_supprimer_clicked()
{
    if(ui->Ticket_affichage->currentIndex().row()==-1)
        QMessageBox::information(nullptr, QObject::tr("Suppression"),
                                 QObject::tr("Veuillez Choisir un Ticket du Tableau.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    else
    {   QString id=ui->Ticket_affichage->model()->data(ui->Ticket_affichage->model()->index(ui->Ticket_affichage->currentIndex().row(),0)).toString();
        Ticket t(ui->Ticket_affichage->model()->data(ui->Ticket_affichage->model()->index(ui->Ticket_affichage->currentIndex().row(),0)).toString(),ui->Ticket_affichage->model()->data(ui->Ticket_affichage->model()->index(ui->Ticket_affichage->currentIndex().row(),1)).toString(),ui->Ticket_affichage->model()->data(ui->Ticket_affichage->model()->index(ui->Ticket_affichage->currentIndex().row(),2)).toInt(),ui->Ticket_affichage->model()->data(ui->Ticket_affichage->model()->index(ui->Ticket_affichage->currentIndex().row(),3)).toDate());



        QString str = " Vous voulez vraiment supprimer \n le Ticket :";
        int ret = QMessageBox::question(this, tr("Ticket"),str,QMessageBox::Ok|QMessageBox::Cancel);

        switch (ret) {
        case QMessageBox::Ok:
            if (t.supprimer(id)){
                N.notification_supprimerTicket();
                musicAdd.setMedia(QUrl("C:/Users/Utilisateur/Desktop/Nouveau dossier (11)/2ndApp1/supp succ.mp3"));

                    musicAdd.play();
                refresh();


            }
            else
            {

                QMessageBox::critical(0, qApp->tr("Suppression"),
                                      qApp->tr("Ticket non trouvé "), QMessageBox::Cancel);
            }



            break;
        case QMessageBox::Cancel:

            break;
        default:
            // should never be reached
            break;
        }


    }
}

void MainWindow::on_pb_modifier_clicked()
{

    QString id= ui->lineEdit_id1->text();
    QString idc=ui->comboBox_idc1->currentText();
    int prix= ui->lineEdit_prix1->text().toInt();
    QDate datee = ui->dateEdit1->date();







    Ticket t(id,idc,prix,datee);


    QSqlQuery query;

    if (ui->lineEdit_id1->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP IDENTIFIANT!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }

    else if (ui->lineEdit_prix1->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP PRIX!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }
    else{








        bool test=t.modifier();
        if(test)
        {



            N.notification_modifierTicket();
            musicAdd.setMedia(QUrl("C:/Users/Utilisateur/Desktop/Nouveau dossier (11)/2ndApp1/modif succ.mp3"));

                musicAdd.play();
            refresh();
            QMessageBox::information(nullptr, QObject::tr("Modifier un Ticket"),
                                     QObject::tr("Ticket modifie.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);



        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Supprimer Ticket"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }

        ui->lineEdit_id1->clear();
        ui->lineEdit_prix1->clear();


    }
}

void MainWindow::on_Ticket_affichage_activated(const QModelIndex &index)
{

    QString id=ui->Ticket_affichage->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("SELECT * FROM TICKET WHERE ID='"+id+"'");
    if(query.exec())
    {
        while(query.next())
        {
            ui->lineEdit_id1->setText(query.value(0).toString());
            ui->lineEdit_prix1->setText(query.value(2).toString());





        }

    }
    else
    {
        QObject::tr("Veuillez Choisir Un ID Du Tableau SVP");
    }


}






//Fin Crud Tickets


//Crud Clients










void MainWindow::on_pb_ajouter_c_clicked()
{
    QString cin= ui->lineEdit_cin->text();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    QString mail = ui->lineEdit_mail->text();
    QString adresse = ui->lineEdit_adresse->text();
    long tel= ui->lineEdit_tel->text().toLong();
    Client c(cin,tel,nom,prenom,adresse,mail);
   historique.save1("prenom :"+ui->lineEdit_prenom->text(),"Nom :"+ui->lineEdit_nom->text());

    if (c.testCin(ui->lineEdit_cin->text())==false)
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP CIN!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }
    else if (ui->lineEdit_nom->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP NOM!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }
    else if (ui->lineEdit_prenom->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP PRENOM!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }
    else if (ui->lineEdit_adresse->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP adresse!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }

    else if (c.testmail(ui->lineEdit_mail->text())==false)
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP MAIL!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }
    else if (c.testnumber(ui->lineEdit_tel->text())==false)
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP NUMERO !!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }





    else {
        bool test=c.ajouter();
        if(test)
        {
            N.notification_ajoutClient();
            refresh();
            musicAdd.setMedia(QUrl("C:/Users/Utilisateur/Desktop/Nouveau dossier (11)/2ndApp1/ajout succe.mp3"));

            musicAdd.play();
            QMessageBox::information(nullptr, QObject::tr("Ajouter un Client"),
                                     QObject::tr("Client ajouté.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Ajouter un Client"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

    }
}






void MainWindow::on_pb_modifier_c_clicked()
{
    QString cin= ui->lineEdit_cin1->text();
    QString nom= ui->lineEdit_nom1->text();
    QString prenom= ui->lineEdit_prenom1->text();
    QString mail = ui->lineEdit_mail1->text();
    QString adresse = ui->lineEdit_adresse1->text();
    long tel= ui->lineEdit_tel1->text().toLong();
    Client c(cin,tel,nom,prenom,adresse,mail);


    QSqlQuery query;
    if (c.testCin(ui->lineEdit_cin1->text())==false)
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP CIN!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }
    else if (ui->lineEdit_nom1->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP NOM!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }
    else if (ui->lineEdit_prenom1->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP PRENOM!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }
    else if (ui->lineEdit_adresse1->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP adresse!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }

    else if (c.testmail(ui->lineEdit_mail1->text())==false)
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP MAIL!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }
    else if (c.testnumber(ui->lineEdit_tel1->text())==false)
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP NUMERO !!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }





    else {

        bool test=c.modifier();
        if(test)
        {



            N.notification_modifierClient();
            musicAdd.setMedia(QUrl("C:/Users/Utilisateur/Desktop/Nouveau dossier (11)/2ndApp1/modif succ.mp3"));

                musicAdd.play();
            refresh();
            QMessageBox::information(nullptr, QObject::tr("Modifier un Client"),
                                     QObject::tr("Client modifie.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);



        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Supprimer Client"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }

        ui->lineEdit_cin1->clear();
        ui->lineEdit_nom1->clear();
        ui->lineEdit_prenom1->clear();
        ui->lineEdit_mail1->clear();
        ui->lineEdit_adresse1->clear();
        ui->lineEdit_tel1->clear();

    }}

void MainWindow::on_pb_supprimer_c_clicked()
{
    if(ui->Client_affichage->currentIndex().row()==-1)
        QMessageBox::information(nullptr, QObject::tr("Suppression"),
                                 QObject::tr("Veuillez Choisir un Client du Tableau.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    else
    {   QString id=ui->Client_affichage->model()->data(ui->Client_affichage->model()->index(ui->Client_affichage->currentIndex().row(),0)).toString();
        Client c(ui->Client_affichage->model()->data(ui->Client_affichage->model()->index(ui->Client_affichage->currentIndex().row(),0)).toString(),ui->Client_affichage->model()->data(ui->Client_affichage->model()->index(ui->Client_affichage->currentIndex().row(),1)).toULongLong(),ui->Client_affichage->model()->data(ui->Client_affichage->model()->index(ui->Client_affichage->currentIndex().row(),2)).toString(),ui->Client_affichage->model()->data(ui->Client_affichage->model()->index(ui->Client_affichage->currentIndex().row(),3)).toString(),ui->Client_affichage->model()->data(ui->Client_affichage->model()->index(ui->Client_affichage->currentIndex().row(),4)).toString(),ui->Client_affichage->model()->data(ui->Client_affichage->model()->index(ui->Client_affichage->currentIndex().row(),5)).toString());



        QString str = " Vous voulez vraiment supprimer \n le Client :";
        int ret = QMessageBox::question(this, tr("Client"),str,QMessageBox::Ok|QMessageBox::Cancel);

        switch (ret) {
        case QMessageBox::Ok:
            if (c.supprimer(id)){
                N.notification_supprimerClient();
                musicAdd.setMedia(QUrl("C:/Users/Utilisateur/Desktop/Nouveau dossier (11)/2ndApp1/supp succ.mp3"));

                    musicAdd.play();
                refresh();

            }
            else
            {

                QMessageBox::critical(0, qApp->tr("Suppression"),
                                      qApp->tr("Client non trouvé "), QMessageBox::Cancel);
            }



            break;
        case QMessageBox::Cancel:

            break;
        default:
            // should never be reached
            break;
        }


    }
}

void MainWindow::on_Client_affichage_activated(const QModelIndex &index)
{

    QString cin=ui->Client_affichage->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("SELECT * FROM CLIENT WHERE CIN='"+cin+"'");
    if(query.exec())
    {
        while(query.next())
        {
            ui->lineEdit_cin1->setText(query.value(0).toString());
            ui->lineEdit_tel1->setText(query.value(1).toString());
            ui->lineEdit_nom1->setText(query.value(2).toString());

            ui->lineEdit_prenom1->setText(query.value(3).toString());
            ui->lineEdit_adresse1->setText(query.value(4).toString());
            ui->lineEdit_mail1->setText(query.value(5).toString());




        }

    }
    else
    {
        QObject::tr("Veuillez Choisir Un ID Du Tableau SVP");
    }

}
//Fin Crud Commandes





void MainWindow::on_recherche_client_textChanged()
{
    if(ui->recherche_client->text()!="")
    {      //  QString b=ui->comboBox_recherche_client->currentText();
        QString a=ui->recherche_client->text();
        ui->Client_affichage->setModel(tmp_Client.displayClause("WHERE (CIN LIKE '%"+a+"%' OR NOM LIKE '%"+a+"%' OR PRENOM LIKE '%"+a+"%' OR ADRESSE LIKE '%"+a+"%' OR MAIL LIKE '%"+a+"%')"));
    }
    else
        ui->Client_affichage->setModel(tmp_Client.afficher());
}

void MainWindow::on_recherche_ticket_textChanged()
{
    if(ui->recherche_ticket->text()!="")
    {      //  QString b=ui->comboBox_recherche_ticket->currentText();
        QString a=ui->recherche_ticket->text();
        ui->Ticket_affichage->setModel(tmp_Ticket.displayClause("WHERE ( ID LIKE '%"+a+"%' OR IDC LIKE '%"+a+"%' OR PRIX LIKE '%"+a+"%' OR PRIX LIKE '%"+a+"%' OR DATEE LIKE '%"+a+"%')"));
    }
    else
        ui->Ticket_affichage->setModel(tmp_Ticket.afficher());
}

void MainWindow::on_tri_croissant_Client_clicked()
{
    ui->Client_affichage->setModel(tmp_Client.tricroissant());

}

void MainWindow::on_tri_deccroissant_Client_clicked()
{
    ui->Client_affichage->setModel(tmp_Client.trideccroissant());

}

void MainWindow::on_tri_croissant_ticket_clicked()
{
    ui->Ticket_affichage->setModel(tmp_Ticket.tricroissant());

}

void MainWindow::on_tri_deccroissant_ticket_clicked()
{
    ui->Ticket_affichage->setModel(tmp_Ticket.trideccroissant());

}



void MainWindow::on_stat_ticket_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from TICKET where PRIX < 5 ");
    float salaire=model->rowCount();
    model->setQuery("select * from TICKET where PRIX  between 5 and 10 ");
    float salairee=model->rowCount();
    model->setQuery("select * from TICKET where PRIX>10 ");
    float salaireee=model->rowCount();
    float total=salaire+salairee+salaireee;
    QString a=QString("moins de 5 Dinars "+QString::number((salaire*100)/total,'f',2)+"%" );
    QString b=QString("entre 5 et 10 Dinars "+QString::number((salairee*100)/total,'f',2)+"%" );
    QString c=QString("+10 Dinars "+QString::number((salaireee*100)/total,'f',2)+"%" );
    QPieSeries *series = new QPieSeries();
    series->append(a,salaire);
    series->append(b,salairee);
    series->append(c,salaireee);
    if (salaire!=0)
    {QPieSlice *slice = series->slices().at(0);
        slice->setLabelVisible();
        slice->setPen(QPen());}
    if ( salairee!=0)
    {
        // Add label, explode and define brush for 2nd slice
        QPieSlice *slice1 = series->slices().at(1);
        //slice1->setExploded();
        slice1->setLabelVisible();
    }
    if(salaireee!=0)
    {
        // Add labels to rest of slices
        QPieSlice *slice2 = series->slices().at(2);
        //slice1->setExploded();
        slice2->setLabelVisible();
    }
    // Create the chart widget
    QChart *chart = new QChart();
    // Add data to chart with title and hide legend
    chart->addSeries(series);
    chart->setTitle("Pourcentage Par Prix :Nombre Des Tickets "+ QString::number(total));
    chart->legend()->hide();
    // Used to display the chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(1000,500);
    chartView->show();
}


void MainWindow::on_pdf_client_clicked()
{
    QPdfWriter pdf("C:/Users/admin/Desktop/pdfClient.pdf");
    QPainter painter(&pdf);
    int i = 4000;
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 30));
    painter.drawText(2300,1200,"Liste Des Clients");
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 50));
    // painter.drawText(1100,2000,afficheDC);
    painter.drawRect(1500,200,7300,2600);
    //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
    painter.drawRect(0,3000,9600,500);
    painter.setFont(QFont("Arial", 9));
    painter.drawText(300,3300,"CIN");
    painter.drawText(1633,3300,"TEL");
    painter.drawText(2966,3300,"NOM");
    painter.drawText(4299,3300,"PRENOM");
    painter.drawText(5632,3300,"ADRESSE");
    painter.drawText(6965,3300,"MAIL");


    QSqlQuery query;
    query.prepare("select * from CLIENT");
    query.exec();
    while (query.next())
    {
        painter.drawText(300,i,query.value(0).toString());
        painter.drawText(1633,i,query.value(1).toString());
        painter.drawText(2966,i,query.value(2).toString());
        painter.drawText(4299,i,query.value(3).toString());
        painter.drawText(5632,i,query.value(4).toString());
        painter.drawText(6965,i,query.value(5).toString());



        i = i +500;
    }
    int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/admin/Desktop/pdfClient.pdf"));

        painter.end();
    }
    if (reponse == QMessageBox::No)
    {
        painter.end();
    }
}

void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")


        N.mail_Ticket();
    musicAdd.setMedia(QUrl("C:/Users/Utilisateur/Desktop/Nouveau dossier (11)/2ndApp1/email envoye.mp3"));

        musicAdd.play();
}

void MainWindow::on_sendBtn_3_clicked()
{
    Smtp* smtp = new Smtp("yousefksouri1122@gmail.com","youssefksouri01","smtp.gmail.com",465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    smtp->sendMail("yousefksouri1122@gmail.com","oussamasaid929@gmail.com",ui->subject->text(),ui->msg->toPlainText());
}







void MainWindow::on_webb_clicked()
{
    QString link="http://www.google.com";
               QDesktopServices::openUrl(QUrl(link));
}



void MainWindow::on_pushButton_emailfilm_clicked()
{

        QItemSelectionModel *select = ui->tablefilm_affichefilm->selectionModel();


            QString nom=select->selectedRows(1).value(0).data().toString();



           QDialog *d=new Dialog(nom,this);
            d->show();
            d->exec();


}



void MainWindow::on_pushButton_emaileven_clicked()
{

}

void MainWindow::on_web_2_clicked()
{
    QString link="http://www.google.com";
           QDesktopServices::openUrl(QUrl(link));
}




void MainWindow::on_ajouter_clicked()
{

    int ref = ui->id->text().toInt();
    int idc= ui->id_c->currentText().toInt();

    QString date= ui->date->text();
    QString heure= ui->heure->text();
    QString qualite=ui->qualite->text();

  projection p(ref,date,heure,idc,qualite);
  bool test=p.ajouter();
  if(test)
{ui->tableView_3->setModel(tmprec.afficher());//refresh
      ui->id_m->setModel(tmprec.Modelid());
      ui->id_s->setModel(tmprec.Modelid());
QMessageBox::information(nullptr, QObject::tr("Ajouter un projection"),
                  QObject::tr("projection ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un projection"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_modifier_clicked()
{
    int ref= ui->id_m->currentText().toInt();
    int idc= ui->id_cat_m->currentText().toInt();
    QString qualite=ui->qualite_m->text();
    QString date= ui->date_m->text();
    QString heure= ui->heure_m->text();
    projection p;

    if(p.rech(ref)){
           bool test = p.modifier(ref,date,heure,idc,qualite);
           if(test){
               ui->tableView->setModel(tmpsalle.afficher());
               ui->id_c->setModel(tmprec.Modelid_salle());
               ui->id_cat_m->setModel(tmprec.Modelid_salle());
               ui->id_m->setModel(tmpsalle.Modelid());
               ui->id_s->setModel(tmpsalle.Modelid());
               QMessageBox::information(nullptr,QObject::tr("commande modifié"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
           }}
}

void MainWindow::on_supprimer_clicked()
{
    int rec = ui->id_s->currentText().toInt();
    bool test=tmprec.supprimer(rec);
    if(test)
    {ui->tableView->setModel(tmprec.afficher());//refresh
        ui->id_c->setModel(tmprec.Modelid_salle());
        ui->id_cat_m->setModel(tmprec.Modelid_salle());
        ui->id_m->setModel(tmprec.Modelid());
        ui->id_s->setModel(tmprec.Modelid());
        QMessageBox::information(nullptr, QObject::tr("Supprimer une projection"),
                    QObject::tr("projection supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une projection"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow:: refreshyoussef()
{
    ui->tableView_3->setModel(tmpsalle.afficher());
    ui->id_m->setModel(tmpsalle.Modelid());
    ui->id_s->setModel(tmpsalle.Modelid());
    ui->id->setValidator( new QIntValidator(0, 100, this) );






}


void MainWindow::on_retour_button_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_retour_button_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_retour_button_5_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}



void MainWindow::on_retour_button_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_retour_button_7_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_ajouter1_clicked()
{

    int ref = ui->id->text().toInt();
    int cap = ui->capacite->text().toInt();
    QString  disponibilite = ui->comboBox->currentText();
  salle p(ref,cap,disponibilite);
  bool test=p.ajouter();
  if(test)
{ui->tableView->setModel(tmprec.afficher());//refresh
      ui->id_m->setModel(tmprec.Modelid());
      ui->id_s->setModel(tmprec.Modelid());
QMessageBox::information(nullptr, QObject::tr("Ajouter un salle"),
                  QObject::tr("salle ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un salle"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_modifier1_clicked()
{
    int id= ui->id_m->currentText().toInt();
    QString disp= ui->comboBox_m->currentText();
    int cap=ui->capacite_m->text().toInt();
    salle p;

    if(p.rech(id)){
           bool test = p.modifier(id,disp,cap);
           if(test){
               ui->tableView->setModel(tmprec.afficher());
               ui->id_s->setModel(tmprec.Modelid());
               QMessageBox::information(nullptr,QObject::tr("commande modifié"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
           }}


    }




void MainWindow::on_supprimer1_clicked()
{
    int rec = ui->id_s->currentText().toInt();
    bool test=tmprec.supprimer(rec);
    if(test)
    {ui->tableView->setModel(tmprec.afficher());//refresh
        ui->id_m->setModel(tmprec.Modelid());
        ui->id_s->setModel(tmprec.Modelid());
        QMessageBox::information(nullptr, QObject::tr("Supprimer une produit"),
                    QObject::tr("produit supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une produit"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    }




void MainWindow::on_checkBox_clicked(bool checked)
{
    if (checked){etat=1;
        etat1=1;
       }
    else if(checked!=1){
        etat=0;
        etat1=0;
    } qDebug () << "checked" << etat;

}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    QString valeur=arg1;
        champ=ui->comboBox_13->currentText();
        ui->tableView_4->setModel(tmpsalle.recherchee(champ,valeur,etat1));
}








