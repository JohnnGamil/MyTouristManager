#include "addpackage.h"
#include "ui_addpackage.h"

AddPackage::AddPackage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddPackage)
{
    ui->setupUi(this);
    // Set a background image for the dialog
    this->setStyleSheet("QDialog {"
                        "    background-image: url(:/res/StateOfLibery5.jpg);"
                        "    background-position: center;"
                        "    background-repeat: no-repeat;"
                        "    background-attachment: fixed;"
                        "    background-size: cover;"
                        "}");
    // Ensure the QTableView has a solid background
    // ui->formLayoutWidget->setStyleSheet("formLayout {"
    //                              "    background-color: #273746 ;"
    //                              "    border: 1px solid #ccc;"
    //                              "}");
}

AddPackage::~AddPackage()
{
    delete ui;
}

void AddPackage::on_bntSave_clicked()
{
    QString packageName = ui->txtPackageName->text();
    QString PackageDescription = ui->txtDescription->toPlainText();
    QString amount = ui->txtAmount->text();

    qDebug()<<"Package Name: "<<packageName<<" Package Description: "<<PackageDescription<<" Amount: "<<amount;

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("F:/MyTouristManager/MyTouristManager.db");

    if(QFile::exists("F:/MyTouristManager/MyTouristManager.db")){
        qDebug()<< "Database File Exists";
    }else{
        qDebug()<<"Database File Doesn't Exists";
        return;
    }

    if(!database.open()){
        qDebug()<<"Error: Unable to open Database";
        return;
    }else{
        qDebug()<<"Database open Successfully..";
    }

    QSqlQuery query(database);
    query.prepare("INSERT INTO Package (PackageName, PackageDescription, Amount) VALUES (:packageName, :packageDescription, :amount)");
    query.bindValue(":packageName", packageName);
    query.bindValue(":packageDescription", PackageDescription);
    query.bindValue(":amount", amount);
    query.exec();
    qDebug() << "Last Error: "<<query.lastError().text();
    database.close();


}


void AddPackage::on_bntReset_clicked()
{
    ui->txtPackageName->clear();
    ui->txtDescription->clear();
    ui->txtAmount->clear();
}

