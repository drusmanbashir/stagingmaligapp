#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableView>
#include <QSqlRecord>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new QSqlTableModel(this);
    model->setTable("staging");
    model->select();
//    model->setHeaderData(0, Qt::Vertical, tr("ID"));
//    model->setHeaderData(1, Qt::Vertical, tr("Region"));
//    model->setHeaderData(2, Qt::Vertical, tr("T1"));
//    model->setHeaderData(3, Qt::Vertical, tr("N1"));
//    model->setHeaderData(4, Qt::Vertical, tr("M1"));

//    displayTNM(0);




}



void MainWindow::displayTNM(int row)
{
    QModelIndex index = model->index(row, 1);
    QSqlRecord record = model->record(index.row());
    QString text = "JOJO";
    QString region = record.value("region").toString();
    QString t = record.value("t").toString();
    QString n = record.value("n").toString();
    QString m = record.value("m").toString();

    QSqlQuery query ("SELECT n FROM staging");
    QString data;
    while (query.next()){
        data += query.value(0).toString();

    }
    ui->outputLabel->setText(data);

    ui->regionLabel->setText(region);
    ui->tLabel->setText(t);
    ui->tLabel->adjustSize();
    ui->nLabel->setText(n);
    ui->mLabel->setText(m);

}


QString MainWindow::name()
{
    return m_name;
}

void MainWindow::setName(const QString &n)
{
    m_name = n;
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_quitButton_clicked()
{
   qApp->quit();
}

void MainWindow::on_rectumBut_clicked()
{

}

void MainWindow::on_lungBut_clicked()
{
    qDebug()<<"CALLED THIS METHOD";
}

void MainWindow::on_hnBut_clicked()
{

}

void MainWindow::on_stomachBut_clicked()
{
    displayTNM(1);
}
