#include "historique.h"
#include"QDateTime"
historique::historique()
{

}
void historique::save(QString genre,QString nom)
{    QFile file ("C:/Users/Utilisateur/Desktop/Nouveau dossier (11)/2ndApp1/historiquefilm.txt");
     if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
      qDebug()<<"erreur";
     QTextStream out(&file);
     out << genre+"\n"+nom << "\n";
}
QString historique::load()
{   tmp="";
    QFile file("C:/Users/Utilisateur/Desktop/Nouveau dossier (11)/2ndApp1/historiquefilm.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
      tmp="";

    QTextStream in(&file);

   while (!in.atEnd()) {

         QString myString = in.readLine();
         tmp+=myString+"\n";

   }
   return tmp;

   mFilename="C:/Users/Utilisateur/Desktop/Nouveau dossier (11)/2ndApp1/historique.txt";
   mFilename1="C:/Users/Utilisateur/Desktop/Nouveau dossier (11)/2ndApp1/historique.txt";
   }
   QString historique::read()
   {
   QFile mFile(mFilename);
   if (!mFile.open(QFile::ReadOnly | QFile::Text))
   {
       qDebug () <<"il ne peut pas";
   }
   QTextStream in (&mFile);
   QString text=mFile.readAll();
   mFile.close();
   return  text;
   }
   QString historique::read1()
   {
   QFile mFile(mFilename1);
   if (!mFile.open(QFile::ReadOnly | QFile::Text))
   {
       qDebug () <<"il ne peut pas";
   }
   QTextStream in (&mFile);
   QString text=mFile.readAll();
   mFile.close();
   return  text;
   }
   void historique::write(QString text)
   {
       QString aux=read();

       QDateTime datetime = QDateTime::currentDateTime();
       QString date =datetime.toString();
       date+= " ";
       aux+=date;
   QFile mFile(mFilename);
   if (!mFile.open(QFile::WriteOnly | QFile::Text))
   {
       qDebug () <<"il ne peut pas";
   }
   QTextStream out (&mFile);


   aux+=text;
   out << aux << "\n";
   mFile.flush();
   mFile.close();

   }
   void historique::write1(QString text)
   {
       QString aux=read();

       QDateTime datetime = QDateTime::currentDateTime();
       QString date =datetime.toString();
       date+= " ";
       aux+=date;
   QFile mFile(mFilename1);
   if (!mFile.open(QFile::WriteOnly | QFile::Text))
   {
       qDebug () <<"il ne peut pas";
   }
   QTextStream out (&mFile);


   aux+=text;
   out << aux << "\n";
   mFile.flush();
   mFile.close();

   }
   void historique::save1(QString prenom,QString nom)
   {    QFile file ("C:/Users/Utilisateur/Desktop/Nouveau dossier (11)/2ndApp1/historiqueclient.txt");
        if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
         qDebug()<<"erreur";
        QTextStream out(&file);
        out << prenom+"\n"+nom << "\n";


   }
   QString historique::load1()
   {   tmp="";
       QFile file("C:/Users/Utilisateur/Desktop/Nouveau dossier (11)/2ndApp1/historiqueclient.txt");
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
         tmp="";

       QTextStream in(&file);

      while (!in.atEnd()) {

            QString myString = in.readLine();
            tmp+=myString+"\n";
}  return tmp;
   }
