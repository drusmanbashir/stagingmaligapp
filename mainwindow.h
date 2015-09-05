#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSqlQuery>
#include <QDebug>
#include <QSqlTableModel>
#include <QMainWindow>
#include <QStyledItemDelegate>
#include <QSet>
#include <QList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_PROPERTY (QString printQuery READ printQuerya WRITE setProperty)
    
public:
    Q_INVOKABLE QStringList getRegionNames (){
        QSqlQuery query;
        QList<QString> names;
        query.exec("select region from staging;");
        while(query.next())
        names <<query.value(0).toString();
        QSet<QString> stringSet = QSet<QString>::fromList(names);
        qDebug()<<stringSet.count();
        names = stringSet.toList();
        return names;
    }
    Q_INVOKABLE QStringList getOrganNames(QString regionName){
        QSqlQuery query;
        QStringList names;
        query.prepare("Select organ from staging where region ==:regionID");
        query.bindValue(":regionID", regionName);
        query.exec();
        while(query.next()){
            names<<query.value(0).toString();

        }
        return names;
    }

    Q_INVOKABLE QStringList getTNM(QString organName){
        QSqlQuery query;
        query.prepare("SELECT * FROM staging WHERE organ == :organID");
        query.bindValue(":organID", organName);
        query.exec();
        QStringList result;
        while (query.next()){
            result<< query.value(1).toString();
            result<< query.value(2).toString(); // t
            result<< query.value(3).toString(); // n
            result<< query.value(4).toString(); // m
            result<< query.value(9).toString(); //oncoimage
            result<<query.value(10).toString();



        }
        return result;
    }

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void displayTNM(int row);

    void setName(const QString &);

    void setProperty (const QString &a){
        m_name = a;
     //   emit propertyChanged();
    }

   QString printQuerya(){
        QSqlQuery query ("SELECT t FROM staging");
        QString result;
        while (query.next()){
            result+= query.value(0).toString();

        }

        return result;
    }
        ;

private slots:

    QString name() ;


    
    void on_quitButton_clicked();

    void on_rectumBut_clicked();

    void on_lungBut_clicked();

    void on_hnBut_clicked();

    void on_stomachBut_clicked();

private:
    QSqlTableModel *model;
    Ui::MainWindow *ui;
    QString m_name;
};

class ViewDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    ViewDelegate(QWidget *parent = 0);
};


#endif // MAINWINDOW_H
