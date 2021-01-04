#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QMessageBox>
#include "film.h"
#include"even.h"
#include "historique.h"
#include <QSystemTrayIcon>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class QSystemTrayIcon;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QRegExp MRE;
    ~MainWindow();
    void ref();

private slots:


    void on_pushButton_4_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_even_clicked();

    void on_lineEdit_nom_returnPressed();
    void on_pushButton_6_clicked();

    void on_comboBox2_activated(const QString &arg1);




    void on_pushButton_email_clicked();

    void on_pushButton_impr_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_modif_clicked();

    void on_pushButton_supprimer_2_clicked();

    void on_web_clicked();

private:

    Ui::MainWindow *ui;
    film tempfilm;
    even tempeven;
    historique historique;
    QSystemTrayIcon *mSystemTrayIcon;




};
#endif // MAINWINDOW_H
