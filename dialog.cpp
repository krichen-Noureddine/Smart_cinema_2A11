#include "dialog.h"
#include "ui_dialog.h"
#include "smtp.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

       ui->server->setText("smtp.gmail.com");
       ui->port->setText("465");
}
Dialog::Dialog(QString,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    QString contenu="Contenu";
    ui->setupUi(this);
    ui->server->setText("smtp.gmail.com");
    ui->port->setText("465");

    ui->uname->setText("noureddine.krichen@esprit.tn");
    ui->passwd->setText("191JMT1735");
    ui->passwd->setEchoMode(QLineEdit::Password);

}
Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_2_clicked()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->passwd->text(), ui->server->text(), ui->port->text().toInt());

    smtp->sendMail(ui->uname->text(), ui->recipient->text() , "subject" ,ui->message->toPlainText());

}
