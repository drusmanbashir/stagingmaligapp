/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QPushButton *lungBut;
    QPushButton *hnBut;
    QPushButton *stomachBut;
    QPushButton *rectumBut;
    QPushButton *mesoBut;
    QPushButton *quitButton;
    QGroupBox *groupBox_2;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *nLabel;
    QLabel *tLabel;
    QLabel *mLabel;
    QLabel *regionLabel;
    QLabel *outputLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 661);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(40, 20, 131, 201));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lungBut = new QPushButton(groupBox);
        lungBut->setObjectName(QStringLiteral("lungBut"));

        verticalLayout->addWidget(lungBut);

        hnBut = new QPushButton(groupBox);
        hnBut->setObjectName(QStringLiteral("hnBut"));

        verticalLayout->addWidget(hnBut);

        stomachBut = new QPushButton(groupBox);
        stomachBut->setObjectName(QStringLiteral("stomachBut"));

        verticalLayout->addWidget(stomachBut);

        rectumBut = new QPushButton(groupBox);
        rectumBut->setObjectName(QStringLiteral("rectumBut"));

        verticalLayout->addWidget(rectumBut);

        mesoBut = new QPushButton(groupBox);
        mesoBut->setObjectName(QStringLiteral("mesoBut"));

        verticalLayout->addWidget(mesoBut);

        quitButton = new QPushButton(centralWidget);
        quitButton->setObjectName(QStringLiteral("quitButton"));
        quitButton->setGeometry(QRect(200, 10, 80, 23));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(280, 40, 481, 591));
        QPalette palette;
        QBrush brush(QColor(193, 239, 123, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        groupBox_2->setPalette(palette);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 40, 61, 71));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 290, 51, 51));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 440, 51, 41));
        nLabel = new QLabel(groupBox_2);
        nLabel->setObjectName(QStringLiteral("nLabel"));
        nLabel->setGeometry(QRect(120, 270, 291, 111));
        tLabel = new QLabel(groupBox_2);
        tLabel->setObjectName(QStringLiteral("tLabel"));
        tLabel->setGeometry(QRect(110, 30, 331, 221));
        QPalette palette1;
        QBrush brush1(QColor(0, 85, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        QBrush brush2(QColor(239, 99, 237, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush2);
        QBrush brush3(QColor(255, 85, 127, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush3);
        QBrush brush4(QColor(137, 149, 255, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush4);
        QBrush brush5(QColor(85, 255, 255, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::NoRole, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::NoRole, brush5);
        QBrush brush6(QColor(190, 190, 190, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        QBrush brush7(QColor(239, 235, 231, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::NoRole, brush5);
        tLabel->setPalette(palette1);
        tLabel->setWordWrap(true);
        mLabel = new QLabel(groupBox_2);
        mLabel->setObjectName(QStringLiteral("mLabel"));
        mLabel->setGeometry(QRect(130, 410, 211, 61));
        regionLabel = new QLabel(centralWidget);
        regionLabel->setObjectName(QStringLiteral("regionLabel"));
        regionLabel->setGeometry(QRect(430, 10, 121, 41));
        outputLabel = new QLabel(centralWidget);
        outputLabel->setObjectName(QStringLiteral("outputLabel"));
        outputLabel->setGeometry(QRect(10, 270, 221, 321));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette2.setBrush(QPalette::Active, QPalette::NoRole, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::NoRole, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::NoRole, brush5);
        outputLabel->setPalette(palette2);
        outputLabel->setWordWrap(true);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Sites", 0));
        lungBut->setText(QApplication::translate("MainWindow", "Lung", 0));
        hnBut->setText(QApplication::translate("MainWindow", "HeadNeck", 0));
        stomachBut->setText(QApplication::translate("MainWindow", "Stomach", 0));
        rectumBut->setText(QApplication::translate("MainWindow", "Rectum", 0));
        mesoBut->setText(QApplication::translate("MainWindow", "Mesothelium", 0));
        quitButton->setText(QApplication::translate("MainWindow", "Quit", 0));
        groupBox_2->setTitle(QString());
        label_2->setText(QApplication::translate("MainWindow", "T Stage", 0));
        label_4->setText(QApplication::translate("MainWindow", "N Stage", 0));
        label_6->setText(QApplication::translate("MainWindow", "M Stage", 0));
        nLabel->setText(QApplication::translate("MainWindow", "T1", 0));
        tLabel->setText(QString());
        mLabel->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        regionLabel->setText(QString());
        outputLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
