#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QMessageBox>
#include "employe.h"
#include "connection.h"
#include "poste.h"
#include "film.h"
#include"even.h"
#include "historique.h"
#include <QSystemTrayIcon>
#include "ticket.h"
#include "client.h"
#include "notification.h"
#include <QMediaPlayer>
#include <QPieSeries>
#include <salle.h>
#include <projection.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
      connection cn;
      QRegExp MRE;
      void ref();


private slots:

    void login();
    void on_ajouter_button_clicked();
    void on_login_button_clicked();

    void on_SUPPRIMER8BUTTON_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_recherche_clicked();

    void on_tri_button_clicked();

    void on_modifier_button_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_ajouter_button_2_clicked();

    void on_pushButton_4_clicked();

    void on_modifier_button_2_clicked();



    void on_SUPPRIMER8BUTTON_2_clicked();

    void on_tri_button_2_clicked();

    void on_retour_button_2_clicked();

    void on_retour_button_clicked();

    void on_exporter_button_clicked();

    void on_exporter_button_2_clicked();

    void on_pushButton_6_clicked();


    void on_pushButton_ajouterfilm_clicked();

    void on_pushButton_supprimerfilm_clicked();


    void on_pushButton_ajoutereven_clicked();

    void on_lineEdit_nom_returnPressed();
    void on_pushButton_modifierfilm_clicked();

    void on_comboBox_trifilm_activated(const QString &arg1);

void on_pushButton_rechercherfilm_clicked();




    void on_pushButton_imprimerfilm_clicked();

    void on_pushButton_rechercherfilme_clicked();

    void on_pushButton_modifiereven_clicked();

    void on_pushButton_supprimereven_clicked();













    void on_pb_ajouter_c_clicked();

    void on_pb_modifier_c_clicked();

    void on_pb_supprimer_c_clicked();

    void on_Client_affichage_activated(const QModelIndex &index);




    void on_pb_modifier_clicked();

    void on_pb_ajouter_clicked();


    void on_Ticket_affichage_activated(const QModelIndex &index);

    void on_recherche_client_textChanged();

    void on_recherche_ticket_textChanged();

    void on_tri_croissant_Client_clicked();

    void on_tri_deccroissant_Client_clicked();

    void on_tri_croissant_ticket_clicked();

    void on_tri_deccroissant_ticket_clicked();


    void on_stat_ticket_clicked();

    void on_pdf_client_clicked();

    void on_sendBtn_3_clicked();
    void mailSent(QString);









    void on_webb_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_emailfilm_clicked();





    void on_pushButton_emaileven_clicked();

    void on_web_2_clicked();

    void on_ajouter1_clicked();

    void on_modifier_clicked();

    void on_supprimer_clicked();
    void refreshyoussef();
    void on_ajouter_clicked();
void refresh();
    void on_modifier1_clicked();

    void on_supprimer1_clicked();

    void on_checkBox_clicked(bool checked);

    void on_lineEdit_textChanged(const QString &arg1);










    void on_pushButton_8_clicked();

    void on_retour_button_3_clicked();

    void on_retour_button_4_clicked();

    void on_retour_button_5_clicked();



    void on_retour_button_6_clicked();

    void on_retour_button_7_clicked();




    void on_pb_supprimer_clicked();

private:
    Ui::MainWindow *ui;
    Employe tempemploye;
    poste tempposte ;
    film tempfilm;
        even tempeven;
historique historique;
        QSystemTrayIcon *mSystemTrayIcon;

        Ticket tmp_Ticket;
        Client tmp_Client;
        Notification N;
           projection tmprec;

        QMediaPlayer musicAdd;
        QString disp;
        salle tmpsalle;
        int etat1=0,etat=0;
        QString champ;
};
#endif // MAINWINDOW_H
