/********************************************************************************
** Form generated from reading UI file 'registertourist.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERTOURIST_H
#define UI_REGISTERTOURIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_RegisterTourist
{
public:
    QPushButton *btnSave;
    QPushButton *btnReset;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QTextEdit *txtPackageDescription;
    QLineEdit *txtFirstName;
    QLineEdit *txtMiddleName;
    QLineEdit *txtLastName;
    QLineEdit *txtPassportNo;
    QLineEdit *txtContactNo;
    QLineEdit *txtPermanentAddress;
    QComboBox *cmbChoosePackage;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;

    void setupUi(QDialog *RegisterTourist)
    {
        if (RegisterTourist->objectName().isEmpty())
            RegisterTourist->setObjectName("RegisterTourist");
        RegisterTourist->resize(750, 750);
        RegisterTourist->setMinimumSize(QSize(750, 750));
        RegisterTourist->setMaximumSize(QSize(750, 750));
        RegisterTourist->setStyleSheet(QString::fromUtf8(""));
        btnSave = new QPushButton(RegisterTourist);
        btnSave->setObjectName("btnSave");
        btnSave->setGeometry(QRect(530, 640, 141, 51));
        QFont font;
        font.setPointSize(15);
        font.setItalic(true);
        btnSave->setFont(font);
        btnReset = new QPushButton(RegisterTourist);
        btnReset->setObjectName("btnReset");
        btnReset->setGeometry(QRect(350, 640, 141, 51));
        btnReset->setFont(font);
        label = new QLabel(RegisterTourist);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 40, 121, 41));
        QFont font1;
        font1.setPointSize(17);
        label->setFont(font1);
        label_2 = new QLabel(RegisterTourist);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 100, 161, 31));
        label_2->setFont(font1);
        label_3 = new QLabel(RegisterTourist);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 160, 131, 41));
        label_3->setFont(font1);
        label_4 = new QLabel(RegisterTourist);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 230, 141, 31));
        label_4->setFont(font1);
        label_5 = new QLabel(RegisterTourist);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 290, 131, 31));
        label_5->setFont(font1);
        label_6 = new QLabel(RegisterTourist);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(30, 350, 201, 41));
        label_6->setFont(font1);
        label_7 = new QLabel(RegisterTourist);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(30, 410, 171, 41));
        label_7->setFont(font1);
        label_8 = new QLabel(RegisterTourist);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(30, 510, 131, 28));
        label_8->setFont(font1);
        txtPackageDescription = new QTextEdit(RegisterTourist);
        txtPackageDescription->setObjectName("txtPackageDescription");
        txtPackageDescription->setGeometry(QRect(260, 480, 481, 100));
        txtPackageDescription->setMinimumSize(QSize(0, 100));
        QFont font2;
        font2.setPointSize(15);
        txtPackageDescription->setFont(font2);
        txtFirstName = new QLineEdit(RegisterTourist);
        txtFirstName->setObjectName("txtFirstName");
        txtFirstName->setGeometry(QRect(260, 40, 483, 40));
        txtFirstName->setMinimumSize(QSize(0, 40));
        txtFirstName->setFont(font2);
        txtMiddleName = new QLineEdit(RegisterTourist);
        txtMiddleName->setObjectName("txtMiddleName");
        txtMiddleName->setGeometry(QRect(260, 100, 483, 40));
        txtMiddleName->setMinimumSize(QSize(0, 40));
        txtMiddleName->setMaximumSize(QSize(16777215, 16777215));
        txtMiddleName->setFont(font2);
        txtLastName = new QLineEdit(RegisterTourist);
        txtLastName->setObjectName("txtLastName");
        txtLastName->setGeometry(QRect(260, 160, 483, 40));
        txtLastName->setMinimumSize(QSize(0, 40));
        txtLastName->setFont(font2);
        txtPassportNo = new QLineEdit(RegisterTourist);
        txtPassportNo->setObjectName("txtPassportNo");
        txtPassportNo->setGeometry(QRect(260, 220, 483, 40));
        txtPassportNo->setMinimumSize(QSize(0, 40));
        txtPassportNo->setFont(font2);
        txtContactNo = new QLineEdit(RegisterTourist);
        txtContactNo->setObjectName("txtContactNo");
        txtContactNo->setGeometry(QRect(260, 290, 483, 40));
        txtContactNo->setMinimumSize(QSize(0, 40));
        txtContactNo->setFont(font2);
        txtPermanentAddress = new QLineEdit(RegisterTourist);
        txtPermanentAddress->setObjectName("txtPermanentAddress");
        txtPermanentAddress->setGeometry(QRect(260, 350, 483, 40));
        txtPermanentAddress->setMinimumSize(QSize(0, 40));
        txtPermanentAddress->setFont(font2);
        cmbChoosePackage = new QComboBox(RegisterTourist);
        cmbChoosePackage->setObjectName("cmbChoosePackage");
        cmbChoosePackage->setGeometry(QRect(260, 410, 483, 40));
        cmbChoosePackage->setMinimumSize(QSize(0, 40));
        cmbChoosePackage->setFont(font2);
        label_9 = new QLabel(RegisterTourist);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(150, 50, 16, 16));
        label_9->setFont(font2);
        label_9->setStyleSheet(QString::fromUtf8(""));
        label_10 = new QLabel(RegisterTourist);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(160, 230, 31, 31));
        label_10->setFont(font2);
        label_10->setStyleSheet(QString::fromUtf8(""));
        label_11 = new QLabel(RegisterTourist);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(150, 290, 31, 31));
        label_11->setFont(font2);
        label_11->setStyleSheet(QString::fromUtf8(""));
        label_12 = new QLabel(RegisterTourist);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(235, 360, 21, 21));
        label_12->setFont(font2);
        label_12->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(RegisterTourist);

        QMetaObject::connectSlotsByName(RegisterTourist);
    } // setupUi

    void retranslateUi(QDialog *RegisterTourist)
    {
        RegisterTourist->setWindowTitle(QCoreApplication::translate("RegisterTourist", "Register Tourist", nullptr));
        btnSave->setText(QCoreApplication::translate("RegisterTourist", "Save", nullptr));
        btnReset->setText(QCoreApplication::translate("RegisterTourist", "Reset", nullptr));
        label->setText(QCoreApplication::translate("RegisterTourist", "First Name", nullptr));
        label_2->setText(QCoreApplication::translate("RegisterTourist", "Midldle Name", nullptr));
        label_3->setText(QCoreApplication::translate("RegisterTourist", "Last Name", nullptr));
        label_4->setText(QCoreApplication::translate("RegisterTourist", "Passport No", nullptr));
        label_5->setText(QCoreApplication::translate("RegisterTourist", "Contact No", nullptr));
        label_6->setText(QCoreApplication::translate("RegisterTourist", "Permanent Address", nullptr));
        label_7->setText(QCoreApplication::translate("RegisterTourist", "Choose Package", nullptr));
        label_8->setText(QCoreApplication::translate("RegisterTourist", "Description", nullptr));
        label_9->setText(QCoreApplication::translate("RegisterTourist", "*", nullptr));
        label_10->setText(QCoreApplication::translate("RegisterTourist", "*", nullptr));
        label_11->setText(QCoreApplication::translate("RegisterTourist", "*", nullptr));
        label_12->setText(QCoreApplication::translate("RegisterTourist", "*", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterTourist: public Ui_RegisterTourist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERTOURIST_H
