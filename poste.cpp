#include "poste.h"

poste::poste()
{

}
poste::poste(int a,int b,int c,QString d,QString e)
{

    id_poste=a ;
    nbr_heurs = b;
    jours_conges = c;
    salaire = d;
    prime = e;

}


bool poste::ajouter()
{
  QSqlQuery query;
  QString res= QString::number(nbr_heurs);
  QString res2= QString::number(id_poste);
  QString res3= QString::number(jours_conges);


  query.prepare("insert into POSTEE (id_poste,nbr_heurs,jours_conges,salaire,prime) " "values (:id_poste,:nbr_heurs,:jours_conges,:salaire,:prime)");

  query.bindValue(":id_poste",res);
  query.bindValue(":nbr_heurs",res2);
  query.bindValue(":jours_conges",res3);
  query.bindValue(":salaire",salaire);
  query.bindValue(":prime",prime);

  return query.exec();

}
/*void poste::ajouter(){

    QString req ="INSERT INTO poste VALUES('%1','%2','%3',%4,'%5','%6','%7')";
    req = req.arg(idposte,nbr_heurs,jours_conges,QString::number(salaire),prime,Mdp,QString::number(id_poste));
    QSqlQuery qry;
    qDebug("request :" +req.toLatin1());
    qry.prepare(req);
    bool test;
    test = qry.exec();
    if(test) qDebug("Ajoute avec succes");
    else qDebug("Ajout Failed");

}*/

QSqlQueryModel * poste::afficher()
{
  QSqlQueryModel * model = new QSqlQueryModel();
  model->setQuery("select * from POSTEE");
  model->setHeaderData(0,Qt::Horizontal,"id_poste");
  model->setHeaderData(1,Qt::Horizontal,"nbr_heurs");
  model->setHeaderData(2,Qt::Horizontal,"jours_conges");
  model->setHeaderData(3,Qt::Horizontal,"salaire");
   return model;
}


/*int poste::chercher(QString id){
    //connection db;
    //db.ouvrirConenction();
    QString req = "Select * from poste where idposte = '%1'";
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
    setposte(qry.value(0).toString(),qry.value(1).toString(),qry.value(2).toString(),qry.value(3).toInt(),qry.value(4).toString(),qry.value(5).toString(),qry.value(6).toInt());
    }
    else qDebug("poste Dont Existe !");
   // db.fermerConnection();
    return recCount;

}*/

QSqlQueryModel * poste::chercher_post_id(const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from POSTEE where ((id_poste ) LIKE '%"+aux+"%')");
    model->setHeaderData(0,Qt::Vertical,QObject::tr("id_poste"));
    model->setHeaderData(1,Qt::Vertical,QObject::tr("nbr_heurs"));
    model->setHeaderData(2,Qt::Vertical,QObject::tr("jours_conges"));
    model->setHeaderData(3,Qt::Vertical,QObject::tr("salaire"));
    model->setHeaderData(4,Qt::Vertical,QObject::tr("prime"));

    return model;
}


QSqlQueryModel * poste::chercher_post_nbrh(const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from POSTEE where ((nbr_heurs ) LIKE '%"+aux+"%')");
    model->setHeaderData(0,Qt::Vertical,QObject::tr("id_poste"));
    model->setHeaderData(1,Qt::Vertical,QObject::tr("nbr_heurs"));
    model->setHeaderData(2,Qt::Vertical,QObject::tr("jours_conges"));
    model->setHeaderData(3,Qt::Vertical,QObject::tr("salaire"));
    model->setHeaderData(4,Qt::Vertical,QObject::tr("prime"));

    return model;
}

QSqlQueryModel * poste::chercher_post_slr(const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from POSTEE where ((salaire ) LIKE '%"+aux+"%')");
    model->setHeaderData(0,Qt::Vertical,QObject::tr("id_poste"));
    model->setHeaderData(1,Qt::Vertical,QObject::tr("nbr_heurs"));
    model->setHeaderData(2,Qt::Vertical,QObject::tr("jours_conges"));
    model->setHeaderData(3,Qt::Vertical,QObject::tr("salaire"));
    model->setHeaderData(4,Qt::Vertical,QObject::tr("prime"));

    return model;
}




bool poste::supprimer(int i){
    QSqlQuery qry;
    qry.prepare("Delete from POSTEE where id_poste=:id_poste");
    QString idposte=QString::number(i);
    qry.bindValue(":id_poste",id_poste);
    return qry.exec();
}

bool poste::modifier(){
    QSqlQuery qry;
    qry.prepare ("update POSTEE" "SET id_poste =:id_poste , nbr_heurs=:nbr_heurs , jours_conges=:jours_conges, salaire=:salaire , prime=:prime"  );
    return qry.exec();
}


/*QSqlQueryModel* poste::trie()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QSqlQuery * q = new  QSqlQuery ();
               QSqlQueryModel * model = new  QSqlQueryModel ();
               q->prepare("SELECT * FROM POSTEE order by nbr_heurs ASC");
               q->exec();
               model->setQuery(*q);
               return model;

      //  model->setQuery("select * POSTEE from  ORDER BY id_poste asc");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_poste"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("nbr_heurs"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr(" jours_conges"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("salaire"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("prime"));





    return model;
}


QSqlQueryModel* poste::trie2()
{
    QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("select * POSTEE ORDER BY id_poste desc");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_poste"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("nbr_heurs"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr(" jours_conges"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("salaire"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("prime"));



    return model;
}*/



    QSqlQueryModel* poste::trie()
    {
        QSqlQueryModel* model = new QSqlQueryModel();

            model->setQuery("select *from POSTEE ORDER BY nbr_heurs asc");

            model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_poste"));
             model->setHeaderData(1, Qt::Horizontal, QObject::tr("nbr_heurs"));
             model->setHeaderData(2, Qt::Horizontal, QObject::tr(" jours_conges"));
             model->setHeaderData(3, Qt::Horizontal, QObject::tr("salaire"));
             model->setHeaderData(4, Qt::Horizontal, QObject::tr("prime"));


        return model;
    }


    QSqlQueryModel* poste::trie2()
    {
        QSqlQueryModel* model = new QSqlQueryModel();
            model->setQuery("select *from POSTEE ORDER BY jours_conges desc");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_poste"));
             model->setHeaderData(1, Qt::Horizontal, QObject::tr("nbr_heurs"));
             model->setHeaderData(2, Qt::Horizontal, QObject::tr(" jours_conges"));
             model->setHeaderData(3, Qt::Horizontal, QObject::tr("salaire"));
             model->setHeaderData(4, Qt::Horizontal, QObject::tr("prime"));


        return model;
    }

/*QSqlQueryModel *poste::chercher_personnel_all(QString idposte , QString nbr_heurs , QString prime  )
{

    QString req = "Select * from personnel where upper(matricule) like upper('%1%') and where upper(titre) like upper('%2%') and where upper(departement) like upper('%3%') ";
        req = req.arg(idposte).arg(nbr_heurs).arg(prime) ;
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
    q.prepare("SELECT * FROM posteS ");
    q.exec();
    QString pdf="<br> <h1  style='color:red'>LISTE DES posteS  <br></h1>\n <br> <table>  <tr>  <th>nbr_heurs ET PREnbr_heurs </th> <th>CIN </th> <th>DATE DE NAISSANCE </th> <th> AGE </th> <th>DEPARTEMENT </th> <th>MOBILE </th>    </tr>" ;


    while ( q.next()) {

        pdf= pdf+ " <br> <tr> <td>"+ q.value(1).toString()+" " + q.value(2).toString() +"</td>   <td>" +q.value(0).toString() +"  "" " "</td>   <td>"+q.value(3).toString()+"</td>   <td>"+q.value(6).toString()+" " "ans "  " " "</td>   <td>"+q.value(4).toString()+" </td> <td>"+q.value(5).toString()+" </td>" ;

    }
    doc.setHtml(pdf);
    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
    doc.print(&printer);*/

