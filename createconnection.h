#ifndef CREATECONNECTION_H
#define CREATECONNECTION_H
#include <QSqlQuery>
#include <QMessageBox>
#include <QStandardPaths>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QStringList>


#endif // CREATECONNECTION_H
class Database {

public:
    Database (QString dbname);
    static bool populateDB();
    static bool readTables();

private:
    QSqlDatabase db;


};

Database::Database(QString dbname) {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbname);
    bool ok=db.open();
    qDebug()<<ok;
    if (!db.open()) {
        QMessageBox::critical(0, qApp->tr("Cannot open database"),
            qApp->tr("Unable to establish a database connection.\n"
                     "This example needs SQLite support. Please read "
                     "the Qt SQL driver documentation for information how "
                     "to build it.\n\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
        return false;
    }

}

static bool Database::populateDB(){
    QFile dfile(":/database/tnmdump");
//    QFile dfile("assets:/database/tnmstaging");
//    if (dfile.exists())
//    {
//        dfile.copy("./tnmDB");
//        QFile::setPermissions("./tnmDB",QFile::WriteOwner | QFile::ReadOwner);
//   }

    QString load;
    if (!dfile.open(QFile::ReadOnly | QFile::Text)) {
        return false;
    }
    QTextStream in(&dfile);
    load = in.readAll();
    QSqlQuery query;
    query.exec(load);
return 1;
}
static bool Database::readTables(){
  if (!db.open())
          return false;
          else qDebug()<<"good")

    QStringList tables;
    tables = db.tables();

}

//static bool createTable(){
//    QSqlQuery query;
//    query.exec("create table staging (id int primary key,"
//               "region varchar (20), t1 text, n1 text, m1 text)");
//    query.exec("insert into staging values (1, 'Lung', 'confined to lobe', 'ipsilateral nodes',"
//                "'metastasis to other lung')");
//    query.exec("insert into staging values (2, 'Stomach', 'confined to submucosa', '<5 nodes',"
//                        "'metastasis to other body parts')");
//    return true;
//}
