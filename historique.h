#ifndef HISTORIQUE_H
#define HISTORIQUE_H
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>

class historique
{
    QString tmp;

    void write(QString);
    QString read();
    void write1(QString);
    QString read1();
public:
    historique();
    void save(QString,QString);
        QString load();
        void save1(QString,QString);
        QString load1();
        QString mFilename;
      QString mFilename1;
};

#endif // HISTORIQUE_H
