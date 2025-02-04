/********************************************************************************
** Form generated from reading UI file 'addpackage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPACKAGE_H
#define UI_ADDPACKAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddPackage
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLineEdit *txtPackageName;
    QLineEdit *txtAmount;
    QTextEdit *txtDescription;
    QPushButton *bntSave;
    QPushButton *bntReset;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QDialog *AddPackage)
    {
        if (AddPackage->objectName().isEmpty())
            AddPackage->setObjectName("AddPackage");
        AddPackage->setWindowModality(Qt::WindowModality::WindowModal);
        AddPackage->resize(650, 400);
        AddPackage->setMinimumSize(QSize(650, 400));
        AddPackage->setMaximumSize(QSize(650, 400));
        formLayoutWidget = new QWidget(AddPackage);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(210, 30, 391, 261));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        txtPackageName = new QLineEdit(formLayoutWidget);
        txtPackageName->setObjectName("txtPackageName");
        txtPackageName->setMinimumSize(QSize(0, 35));
        QFont font;
        font.setPointSize(15);
        txtPackageName->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, txtPackageName);

        txtAmount = new QLineEdit(formLayoutWidget);
        txtAmount->setObjectName("txtAmount");
        txtAmount->setMinimumSize(QSize(0, 35));
        txtAmount->setFont(font);

        formLayout->setWidget(2, QFormLayout::FieldRole, txtAmount);

        txtDescription = new QTextEdit(formLayoutWidget);
        txtDescription->setObjectName("txtDescription");
        txtDescription->setMaximumSize(QSize(380, 100));
        txtDescription->setFont(font);

        formLayout->setWidget(1, QFormLayout::FieldRole, txtDescription);

        bntSave = new QPushButton(AddPackage);
        bntSave->setObjectName("bntSave");
        bntSave->setGeometry(QRect(460, 340, 111, 41));
        QFont font1;
        font1.setPointSize(15);
        font1.setItalic(true);
        bntSave->setFont(font1);
        bntReset = new QPushButton(AddPackage);
        bntReset->setObjectName("bntReset");
        bntReset->setGeometry(QRect(320, 340, 111, 41));
        bntReset->setFont(font1);
        label = new QLabel(AddPackage);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 50, 161, 27));
        QFont font2;
        font2.setPointSize(17);
        label->setFont(font2);
        label_2 = new QLabel(AddPackage);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 130, 121, 47));
        label_2->setFont(font2);
        label_3 = new QLabel(AddPackage);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 240, 91, 27));
        label_3->setFont(font2);
        label_4 = new QLabel(AddPackage);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(190, 50, 21, 21));
        label_4->setFont(font);
        label_5 = new QLabel(AddPackage);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(155, 140, 21, 21));
        label_5->setFont(font);
        label_6 = new QLabel(AddPackage);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(120, 240, 16, 21));
        label_6->setFont(font);

        retranslateUi(AddPackage);

        QMetaObject::connectSlotsByName(AddPackage);
    } // setupUi

    void retranslateUi(QDialog *AddPackage)
    {
        AddPackage->setWindowTitle(QCoreApplication::translate("AddPackage", "Add Package", nullptr));
        bntSave->setText(QCoreApplication::translate("AddPackage", "Save", nullptr));
        bntReset->setText(QCoreApplication::translate("AddPackage", "Reset", nullptr));
        label->setText(QCoreApplication::translate("AddPackage", "Package Name ", nullptr));
        label_2->setText(QCoreApplication::translate("AddPackage", "Description", nullptr));
        label_3->setText(QCoreApplication::translate("AddPackage", "Amount", nullptr));
        label_4->setText(QCoreApplication::translate("AddPackage", "*", nullptr));
        label_5->setText(QCoreApplication::translate("AddPackage", "*", nullptr));
        label_6->setText(QCoreApplication::translate("AddPackage", "*", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddPackage: public Ui_AddPackage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPACKAGE_H
