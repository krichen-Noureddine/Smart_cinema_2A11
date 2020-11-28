#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QMessageBox>
#include "film.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QRegExp MRE;
    ~MainWindow();

private slots:


    void on_pushButton_4_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_even_clicked();

    void on_lineEdit_nom_returnPressed();

private:

    Ui::MainWindow *ui;
    film tempfilm;




};
#endif // MAINWINDOW_H
