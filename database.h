#ifndef DATABASE_H
#define DATABASE_H
#include <QSqlQuery>
#include <QMessageBox>
#include <QStandardPaths>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QRegExp>
#include <QListIterator>

#endif //
class Database {

public:
    Database (QString dbname);
    bool populateDB();
    bool readTables();
    bool createDummyTable();

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

    }

    QStringList tableIndex = db.tables();
    if (tableIndex.isEmpty())
        populateDB();
}
bool Database::populateDB(){
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
    QRegExp exp(";\n");

QStringList queries;
queries = load.split(exp);
QListIterator<QString> it (queries);

    QSqlQuery query;

while(it.hasNext()){
     qDebug()<<        query.exec(it.next());

    }


    return 1;
}
bool Database::readTables(){
  if (!db.open())
          return false;
          else qDebug()<<"good";


    QStringList tables;

    QSqlQuery query;
    query.exec("SELECT * FROM staging ;");
            while(query.next()){
        qDebug()<<query.value(1).toString();
    }
    tables = db.tables();
    qDebug()<<tables[0];
//    createDummyTable();

    tables = db.tables();
    qDebug()<<tables[0];
}

bool Database::createDummyTable(){
    QSqlQuery query;
    query.exec("create table dummy (id int primary key,"
               "region varchar (20), t1 text, n1 text, m1 text)");
    query.exec("insert into staging values (1, 'Lung', 'confined to lobe', 'ipsilateral nodes',"
                "'metastasis to other lung')");
    query.exec("insert into staging values (2, 'Stomach', 'confined to submucosa', '<5 nodes',"
                        "'metastasis to other body parts')");
    return true;
}
