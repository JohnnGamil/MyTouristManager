/********************************************************************************
** Form generated from reading UI file 'findpackage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDPACKAGE_H
#define UI_FINDPACKAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_FindPackage
{
public:
    QLabel *label;
    QLineEdit *txtPackageName;
    QPushButton *btnFindPackage;
    QTableView *tableView;

    void setupUi(QDialog *FindPackage)
    {
        if (FindPackage->objectName().isEmpty())
            FindPackage->setObjectName("FindPackage");
        FindPackage->resize(1000, 750);
        FindPackage->setMinimumSize(QSize(1000, 750));
        FindPackage->setMaximumSize(QSize(1000, 750));
        QFont font;
        font.setItalic(true);
        FindPackage->setFont(font);
        FindPackage->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(FindPackage);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 30, 151, 31));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setStrikeOut(false);
        label->setFont(font1);
        txtPackageName = new QLineEdit(FindPackage);
        txtPackageName->setObjectName("txtPackageName");
        txtPackageName->setGeometry(QRect(210, 30, 371, 31));
        QFont font2;
        font2.setPointSize(15);
        font2.setItalic(false);
        txtPackageName->setFont(font2);
        btnFindPackage = new QPushButton(FindPackage);
        btnFindPackage->setObjectName("btnFindPackage");
        btnFindPackage->setGeometry(QRect(670, 20, 141, 41));
        QFont font3;
        font3.setPointSize(12);
        font3.setItalic(true);
        btnFindPackage->setFont(font3);
        tableView = new QTableView(FindPackage);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(20, 90, 961, 641));
        QFont font4;
        font4.setPointSize(12);
        font4.setItalic(false);
        tableView->setFont(font4);
        tableView->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(FindPackage);

        QMetaObject::connectSlotsByName(FindPackage);
    } // setupUi

    void retranslateUi(QDialog *FindPackage)
    {
        FindPackage->setWindowTitle(QCoreApplication::translate("FindPackage", "Find Package", nullptr));
        label->setText(QCoreApplication::translate("FindPackage", "Package Name :", nullptr));
        btnFindPackage->setText(QCoreApplication::translate("FindPackage", "Find Package", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindPackage: public Ui_FindPackage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDPACKAGE_H
