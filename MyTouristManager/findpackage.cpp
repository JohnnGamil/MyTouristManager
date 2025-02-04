#include "findpackage.h"
#include "ui_findpackage.h"

FindPackage::FindPackage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FindPackage),
    model(new QSqlQueryModel(this)) // Initialize the model
{
    ui->setupUi(this);
    // Set the model to the QTableView
    ui->tableView->setModel(model);

    // Set a background image for the dialog
    this->setStyleSheet("QDialog {"
                        "    background-image: url(:/res/StateOfLibery5.jpg);"
                        "    background-position: center;"
                        "    background-repeat: no-repeat;"
                        "    background-attachment: fixed;"
                        "    background-size: cover;"
                        "}");
    // Ensure the QTableView has a solid background
    ui->tableView->setStyleSheet("QTableView {"
                                 "    background-color: #273746 ;"
                                 "    border: 1px solid #ccc;"
                                 "}");
    // Retrieve all data in the table when the dialog opens
    loadAllPackages();
}

FindPackage::~FindPackage()
{
    delete ui;
    delete model;
}


void FindPackage::loadAllPackages()
{
    QString dbPath = "F:/MyTouristManager/MyTouristManager.db";
    QSqlDatabase database = QSqlDatabase::database();
    if (!database.isOpen()) {
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName(dbPath);
        if (!database.open()) {
            qDebug() << "Error: Unable to open Database";
            return;
        }
    }

    QSqlQuery query(database);
    query.prepare("SELECT * FROM Package");
    if (!query.exec()) {
        qDebug() << "Query failed:" << query.lastError().text();
        return;
    }

    model->setQuery(std::move(query));

    // Adjust column headers
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Package Name"));
    model->setHeaderData(2, Qt::Horizontal, tr("Package Description"));
    model->setHeaderData(3, Qt::Horizontal, tr("Amount"));

    // Adjust column widths to match on_btnFindPackage_clicked()
    ui->tableView->setColumnWidth(0, 150);
    ui->tableView->setColumnWidth(1, 200);
    ui->tableView->setColumnWidth(2, 350);
    ui->tableView->setColumnWidth(3, 210);
}


void FindPackage::on_btnFindPackage_clicked()
{
    QString packageName = ui->txtPackageName->text();

    // Check if the database file exists
    if (!QFile::exists("F:/MyTouristManager/MyTouristManager.db")) {
        qDebug() << "Database File Doesn't Exist";
        return;
    }

    // Open the database connection
    QSqlDatabase database = QSqlDatabase::database(); // Reuse existing connection
    if (!database.isOpen()) {
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("F:/MyTouristManager/MyTouristManager.db");
        if (!database.open()) {
            qDebug() << "Error: Unable to open Database";
            return;
        }
    }

    // Prepare and execute the query
    QSqlQuery query(database);
    query.prepare("SELECT * FROM Package WHERE PackageName LIKE :packageName");
    query.bindValue(":packageName", "%" + packageName + "%");

    if (!query.exec()) {
        qDebug() << "Query failed:" << query.lastError().text();
        return;
    }

    // Initialize the model if it doesn't exist
    if (model == nullptr) {
        model = new QSqlQueryModel(this); // Initialize the model
    }

    // Set the query to the model
    model->setQuery(std::move(query));

    // Set the model to the QTableView
    ui->tableView->setModel(model);

    // Adjust column headers (optional)
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Package Name"));
    model->setHeaderData(2, Qt::Horizontal, tr("Package Description"));
    model->setHeaderData(3, Qt::Horizontal, tr("Amount"));

    // Adjust column widths (optional)
    ui->tableView->setColumnWidth(0, 150);
    ui->tableView->setColumnWidth(1, 200); // Set width for the first column
    ui->tableView->setColumnWidth(2, 350); // Set width for the second column
    ui->tableView->setColumnWidth(3, 210); // Set width for the third column

    // Close the database connection (optional, can be reused)
    database.close();
}
