#include "employe.h"


Employe::Employe()
{

}
Employe::Employe(QString a,QString b,QString c,int d,QString e,QString f,int g){

    idEmploye=a;
    nom = b;
    DateNaiss = c;
    NumTel = d;
    Adress = e;
    Mdp = f;
    id_poste = g;
}


bool Employe::ajouter()
{
  QSqlQuery query;
  QString res= QString::number(NumTel);
  QString ress= QString::number(id_poste);

  query.prepare("insert into EMPLOYE (idEmploye,nom,DateNaiss,NumTel,adress,Mdp,id_poste) " "values (:idEmploye,:nom,:DateNaiss,:NumTel,:adress,:Mdp,:id_poste)");

  query.bindValue(":idEmploye",idEmploye);
  query.bindValue(":nom",nom);
  query.bindValue(":DateNaiss",DateNaiss);
  query.bindValue(":NumTel",res);
  query.bindValue(":adress",Adress);
   query.bindValue(":Mdp",Mdp);
   query.bindValue(":id_poste",ress);
  return query.exec();

}
/*void Employe::ajouter(){

    QString req ="INSERT INTO EMPLOYE VALUES('%1','%2','%3',%4,'%5','%6','%7')";
    req = req.arg(idEmploye,nom,DateNaiss,QString::number(NumTel),Adress,Mdp,QString::number(id_poste));
    QSqlQuery qry;
    qDebug("request :" +req.toLatin1());
    qry.prepare(req);
    bool test;
    test = qry.exec();
    if(test) qDebug("Ajoute avec succes");
    else qDebug("Ajout Failed");

}*/

QSqlQueryModel * Employe::afficher()
{
  QSqlQueryModel * model = new QSqlQueryModel();
  model->setQuery("select * from EMPLOYE");
  model->setHeaderData(0,Qt::Horizontal,"idEmploye");
  model->setHeaderData(1,Qt::Horizontal,"nom");
  model->setHeaderData(2,Qt::Horizontal,"DateNaiss");
  model->setHeaderData(3,Qt::Horizontal,"NumTel");
   return model;
}


/*int Employe::chercher(QString id){
    //connection db;
    //db.ouvrirConenction();
    QString req = "Select * from Employe where idEmploye = '%1'";
    req = req.arg(id);
    QSqlQuery qry;
    qDebug("request :" +req.toLatin1());
    qry.prepare(req);
    qry.exec();
    int recCount = 0;
    while( qry.next() )
    {
    recCount++;
    }
    qry.seek(0);
    if(recCount == 1){
    setEmploye(qry.value(0).toString(),qry.value(1).toString(),qry.value(2).toString(),qry.value(3).toInt(),qry.value(4).toString(),qry.value(5).toString(),qry.value(6).toInt());
    }
    else qDebug("Employe Dont Existe !");
   // db.fermerConnection();
    return recCount;

}*/

QSqlQueryModel * Employe::chercher_emp_id(const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from Employe where ((idEmploye ) LIKE '%"+aux+"%')");
    model->setHeaderData(0,Qt::Vertical,QObject::tr("idEmploye"));
    model->setHeaderData(1,Qt::Vertical,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Vertical,QObject::tr("DateNaiss"));
    model->setHeaderData(3,Qt::Vertical,QObject::tr("NumTel"));
    model->setHeaderData(4,Qt::Vertical,QObject::tr("adress"));

    return model;
}


QSqlQueryModel * Employe::chercher_emp_nom(const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from PHOTO where ((nom ) LIKE '%"+aux+"%')");
    model->setHeaderData(0,Qt::Vertical,QObject::tr("idEmploye"));
    model->setHeaderData(1,Qt::Vertical,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Vertical,QObject::tr("DateNaiss"));
    model->setHeaderData(3,Qt::Vertical,QObject::tr("NumTel"));
    model->setHeaderData(4,Qt::Vertical,QObject::tr("adress"));

    return model;
}

QSqlQueryModel * Employe::chercher_emp_mdp(const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from PHOTO where ((MDP ) LIKE '%"+aux+"%')");
    model->setHeaderData(0,Qt::Vertical,QObject::tr("idEmploye"));
    model->setHeaderData(1,Qt::Vertical,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Vertical,QObject::tr("DateNaiss"));
    model->setHeaderData(3,Qt::Vertical,QObject::tr("NumTel"));
    model->setHeaderData(4,Qt::Vertical,QObject::tr("adress"));

    return model;
}




bool Employe::supprimer(int i){
    QSqlQuery qry;
    qry.prepare("Delete from Employe where idEmploye=:idEmploye");
    QString idEmploye=QString::number(i);
    qry.bindValue(":idEmploye",idEmploye);
    return qry.exec();
}

bool Employe::modifier(){
    QSqlQuery qry;
    qry.prepare ("update Employe" "SET idEmploye =:idEmploye , nom=:nom , DateNaiss=:DateNaiss, NumTel=:NumTel , Adress=:Adress , id_poste=:id_poste" );
    return qry.exec();
}


QSqlQueryModel* Employe::trie()
{
   // QSqlQueryModel* model = new QSqlQueryModel();

    QSqlQuery * q = new  QSqlQuery ();
               QSqlQueryModel * model = new  QSqlQueryModel ();
               q->prepare("SELECT * FROM EMPLOYE order by nom ASC");
               q->exec();
               model->setQuery(*q);
               return model;

      //  model->setQuery("select * Employe from  ORDER BY idEmploye asc");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("idEmploye"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr(" DateNaiss"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("NumTel"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESS"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("Mdp"));
         model->setHeaderData(6, Qt::Horizontal, QObject::tr("id_poste"));




    return model;
}


QSqlQueryModel* Employe::trie2()
{
    QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("select * Employe ORDER BY idEmploye desc");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("idEmploye"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr(" DateNaiss"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("NumTel"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESS"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("Mdp"));
         model->setHeaderData(6, Qt::Horizontal, QObject::tr("id_poste"));


    return model;
}

/*QSqlQueryModel *Employe::chercher_personnel_all(QString idEmploye , QString nom , QString adress  )
{

    QString req = "Select * from personnel where upper(matricule) like upper('%1%') and where upper(titre) like upper('%2%') and where upper(departement) like upper('%3%') ";
        req = req.arg(idEmploye).arg(nom).arg(adress) ;
    QSqlQueryModel *model = new QSqlQueryModel;
            model->setQuery(req);
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("TITRE"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("MATRICULE"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("SERVICE"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("DEPARTEMENT"));
            return model ;
}*/



/*QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPrinter printer (QPrinter::PrinterResolution);

    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QSqlQuery q;
    q.prepare("SELECT * FROM EMPLOYES ");
    q.exec();
    QString pdf="<br> <h1  style='color:red'>LISTE DES EMPLOYES  <br></h1>\n <br> <table>  <tr>  <th>NOM ET PRENOM </th> <th>CIN </th> <th>DATE DE NAISSANCE </th> <th> AGE </th> <th>DEPARTEMENT </th> <th>MOBILE </th>    </tr>" ;


    while ( q.next()) {

        pdf= pdf+ " <br> <tr> <td>"+ q.value(1).toString()+" " + q.value(2).toString() +"</td>   <td>" +q.value(0).toString() +"  "" " "</td>   <td>"+q.value(3).toString()+"</td>   <td>"+q.value(6).toString()+" " "ans "  " " "</td>   <td>"+q.value(4).toString()+" </td> <td>"+q.value(5).toString()+" </td>" ;

    }
    doc.setHtml(pdf);
    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
    doc.print(&printer);*/
