#include "mainwindow.h"
#include <QApplication>
#include <QQmlEngine>
#include <QQmlContext>
#include <qqml.h>
#include <QtQuick/QQuickItem>
#include <QtQuick/QQuickView>
#include <qtquick2applicationviewer/qtquick2applicationviewer.h>
//#include "qtquick2applicationviewer.h"
#include "database.h"
#include <QRect>
#include <QGuiApplication>




int main(int argc, char *argv[])
{
QApplication a(argc, argv);
qreal refDpi= 216;
qreal refHeight = 1776;
qreal refWidth = 1080.;





    Database jango("theiiB");

    jango.readTables();

    MainWindow w;
    QtQuick2ApplicationViewer viewer;

    viewer.rootContext()->setContextProperty("mWindow", &w);
    viewer.rootContext()->setContextProperty("regionNames",w.getRegionNames());

    viewer.setSource(QUrl("qrc:/qml/TNM.qml"));

    viewer.showFullScreen();

    viewer.showExpanded();
  //  w.show();
    
    return a.exec();
}
