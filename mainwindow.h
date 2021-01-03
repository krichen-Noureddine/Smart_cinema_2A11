#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QMessageBox>
#include "employe.h"
#include "connection.h"
#include "poste.h"

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

    void on_pushButton_recherche_2_clicked();

    void on_SUPPRIMER8BUTTON_2_clicked();

    void on_tri_button_2_clicked();

    void on_retour_button_2_clicked();

    void on_retour_button_clicked();

    void on_exporter_button_clicked();

    void on_exporter_button_2_clicked();

private:
    Ui::MainWindow *ui;
    Employe tempemploye;
    poste tempposte ;
};
#endif // MAINWINDOW_H
