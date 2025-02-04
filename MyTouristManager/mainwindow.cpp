#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ptrAddPackage = new AddPackage();
    ptrRegisterTourist = new RegisterTourist();
    ptrFindPackage = new FindPackage();
    ptrFindTourist = new FindTourist();

    this->setStyleSheet("QMainWindow {"
                        "    background-image: url(:/res/StateOfLibery2.jpg);"
                        "    background-position: center;"
                        "    background-repeat: no-repeat;"
                        "    background-attachment: fixed;"
                        "    background-size: cover;"
                        "}");

    ui->pushButton->setCursor(Qt::PointingHandCursor);
    ui->pushButton->setStyleSheet("QPushButton {"
                                  "    background-color: #003366;"
                                  "    color: white;"
                                  "    border: 3px solid magenta;"
                                  "    border-radius: 10px;"
                                  "}"
                                  "QPushButton:hover {"
                                  "    background-color: #0055A4;"
                                  "    cursor: pointing;"
                                  "}");

    ui->pushButton_5->setCursor(Qt::PointingHandCursor);
    ui->pushButton_5->setStyleSheet("QPushButton {"
                                  "    background-color: #003366;"
                                  "    color: white;"
                                  "    border: 3px solid magenta;"
                                  "    border-radius: 10px;"
                                  "}"
                                  "QPushButton:hover {"
                                  "    background-color: #0055A4;"
                                  "}");

    ui->pushButton_6->setCursor(Qt::PointingHandCursor);
    ui->pushButton_6->setStyleSheet("QPushButton {"
                                  "    background-color: #003366;"
                                  "    color: white;"
                                  "    border: 3px solid magenta;"
                                  "    border-radius: 10px;"
                                  "}"
                                  "QPushButton:hover {"
                                  "    background-color: #0055A4;"
                                  "}");

    ui->pushButton_7->setCursor(Qt::PointingHandCursor);
    ui->pushButton_7->setStyleSheet("QPushButton {"
                                  "    background-color: #003366;"
                                  "    color: white;"
                                  "    border: 3px solid magenta;"
                                  "    border-radius: 10px;"
                                  "}"
                                  "QPushButton:hover {"
                                  "    background-color: #0055A4;"
                                  "}");


}

MainWindow::~MainWindow()
{
    delete ptrAddPackage;
    delete ptrRegisterTourist;
    delete ptrFindPackage;
    delete ptrFindTourist;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ptrAddPackage->show();
}


void MainWindow::on_pushButton_5_clicked()
{
    ptrRegisterTourist->show();
}


void MainWindow::on_pushButton_6_clicked()
{
    ptrFindPackage->show();
}


void MainWindow::on_pushButton_7_clicked()
{
    ptrFindTourist->show();
}

