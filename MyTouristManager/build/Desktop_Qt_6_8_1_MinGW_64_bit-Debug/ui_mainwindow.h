/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 800);
        MainWindow->setMinimumSize(QSize(1000, 800));
        MainWindow->setMaximumSize(QSize(1000, 800));
        MainWindow->setTabletTracking(false);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(80, 90, 200, 100));
        pushButton->setMinimumSize(QSize(200, 100));
        pushButton->setMaximumSize(QSize(200, 65));
        QFont font;
        font.setPointSize(20);
        pushButton->setFont(font);
        pushButton->setAutoFillBackground(false);
        pushButton->setStyleSheet(QString::fromUtf8(""));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(80, 350, 200, 100));
        pushButton_5->setMinimumSize(QSize(200, 100));
        pushButton_5->setMaximumSize(QSize(200, 100));
        pushButton_5->setFont(font);
        pushButton_5->setStyleSheet(QString::fromUtf8(""));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(80, 220, 200, 100));
        pushButton_6->setMinimumSize(QSize(200, 100));
        pushButton_6->setMaximumSize(QSize(200, 100));
        pushButton_6->setFont(font);
        pushButton_6->setStyleSheet(QString::fromUtf8(""));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(80, 480, 200, 100));
        pushButton_7->setMinimumSize(QSize(200, 100));
        pushButton_7->setMaximumSize(QSize(200, 100));
        pushButton_7->setFont(font);
        pushButton_7->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MyTouristManager 1.0", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Add Pacakge", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Register Tourist", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Find Package", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Find Tourist", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
