/********************************************************************************
** Form generated from reading UI file 'findtourist.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDTOURIST_H
#define UI_FINDTOURIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_FindTourist
{
public:
    QLabel *label;
    QLineEdit *txtTouristName;
    QPushButton *btnFind;
    QTableView *tableView;

    void setupUi(QDialog *FindTourist)
    {
        if (FindTourist->objectName().isEmpty())
            FindTourist->setObjectName("FindTourist");
        FindTourist->resize(1635, 850);
        FindTourist->setMinimumSize(QSize(1635, 850));
        FindTourist->setMaximumSize(QSize(1635, 850));
        FindTourist->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(FindTourist);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 30, 181, 41));
        QFont font;
        font.setPointSize(15);
        label->setFont(font);
        txtTouristName = new QLineEdit(FindTourist);
        txtTouristName->setObjectName("txtTouristName");
        txtTouristName->setGeometry(QRect(230, 40, 351, 31));
        txtTouristName->setFont(font);
        btnFind = new QPushButton(FindTourist);
        btnFind->setObjectName("btnFind");
        btnFind->setGeometry(QRect(640, 40, 151, 31));
        QFont font1;
        font1.setPointSize(15);
        font1.setItalic(true);
        btnFind->setFont(font1);
        tableView = new QTableView(FindTourist);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(20, 120, 1591, 701));
        QFont font2;
        font2.setPointSize(12);
        font2.setItalic(false);
        tableView->setFont(font2);
        tableView->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(FindTourist);

        QMetaObject::connectSlotsByName(FindTourist);
    } // setupUi

    void retranslateUi(QDialog *FindTourist)
    {
        FindTourist->setWindowTitle(QCoreApplication::translate("FindTourist", "Find Tourist", nullptr));
        label->setText(QCoreApplication::translate("FindTourist", "Enter Tourist Name :", nullptr));
        btnFind->setText(QCoreApplication::translate("FindTourist", "Find Tourist", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindTourist: public Ui_FindTourist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDTOURIST_H
