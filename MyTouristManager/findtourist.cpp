#include "findtourist.h"
#include "ui_findtourist.h"
#include <QCompleter>

FindTourist::FindTourist(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FindTourist),
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

    // Setup AutoComplete for the Tourist Name field
    setupAutoComplete();

    // Retrieve all data in the table when the dialog opens
    loadAllTourists();
}

FindTourist::~FindTourist()
{
    delete ui;
    delete model; // Clean up the model
}

void FindTourist::setupAutoComplete()
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
    query.prepare("SELECT DISTINCT FirstName || ' ' || MiddleName || ' ' || LastName FROM Tourist");
    if (!query.exec()) {
        qDebug() << "AutoComplete Query failed:" << query.lastError().text();
        return;
    }

    QStringList nameList;
    while (query.next()) {
        nameList << query.value(0).toString().trimmed();
    }

    QCompleter *completer = new QCompleter(nameList, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setFilterMode(Qt::MatchContains);
    ui->txtTouristName->setCompleter(completer);
}

void FindTourist::loadAllTourists()
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
    query.prepare("SELECT * FROM Tourist");
    if (!query.exec()) {
        qDebug() << "Query failed:" << query.lastError().text();
        return;
    }

    // Set the query results to the model
    model->setQuery(std::move(query));

    // Set the model to the QTableView
    ui->tableView->setModel(model);

    // Adjust column headers (optional)
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("First Name"));
    model->setHeaderData(2, Qt::Horizontal, tr("Middle Name"));
    model->setHeaderData(3, Qt::Horizontal, tr("Last Name"));
    model->setHeaderData(4, Qt::Horizontal, tr("Passport Number"));
    model->setHeaderData(5, Qt::Horizontal, tr("Contact Number"));
    model->setHeaderData(6, Qt::Horizontal, tr("Permanent Address"));
    model->setHeaderData(7, Qt::Horizontal, tr("Package Name"));
    model->setHeaderData(8, Qt::Horizontal, tr("Package Description"));

    // Adjust column widths (optional)
    ui->tableView->setColumnWidth(0, 100);
    ui->tableView->setColumnWidth(1, 120); // Set width for the first column
    ui->tableView->setColumnWidth(2, 120); // Set width for the second column
    ui->tableView->setColumnWidth(3, 120); // Set width for the third column
    ui->tableView->setColumnWidth(4, 150);
    ui->tableView->setColumnWidth(5, 150);
    ui->tableView->setColumnWidth(6, 350);
    ui->tableView->setColumnWidth(7, 150);
    ui->tableView->setColumnWidth(8, 350);
}

void FindTourist::on_btnFind_clicked()
{
    // Retrieve the search text
    QString searchText = ui->txtTouristName->text().trimmed(); // Remove leading/trailing spaces
    qDebug() << "Search text:" << searchText;

    // Database path
    QString dbPath = "F:/MyTouristManager/MyTouristManager.db";
    qDebug() << "Database path:" << dbPath;

    // Set the database path
    QSqlDatabase database = QSqlDatabase::database(); // Reuse existing connection
    if (!database.isOpen()) {
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName(dbPath); // Use the correct path
        if (!database.open()) {
            qDebug() << "Error: Unable to open Database";
            return;
        }
    }

    // Construct the SQL query
    QString queryStr;
    QSqlQuery query(database);

    if (searchText.isEmpty()) {
        queryStr = "SELECT * FROM Tourist";
    } else {
        QStringList searchParts = searchText.split(" ", Qt::SkipEmptyParts); // Split by spaces
        qDebug() << "Search parts:" << searchParts;

        if (searchParts.size() == 3) {
            queryStr = "SELECT * FROM Tourist WHERE "
                       "(FirstName LIKE :firstName AND MiddleName LIKE :middleName AND LastName LIKE :lastName) OR "
                       "PassportNo LIKE :searchText OR "
                       "ContactNo LIKE :searchText OR "
                       "PackageName LIKE :searchText";
        } else if (searchParts.size() == 2) {
            queryStr = "SELECT * FROM Tourist WHERE "
                       "(FirstName LIKE :firstName AND LastName LIKE :lastName) OR "
                       "PassportNo LIKE :searchText OR "
                       "ContactNo LIKE :searchText OR "
                       "PackageName LIKE :searchText";
        } else {
            queryStr = "SELECT * FROM Tourist WHERE "
                       "FirstName LIKE :searchText OR "
                       "PassportNo LIKE :searchText OR "
                       "ContactNo LIKE :searchText OR "
                       "PackageName LIKE :searchText";
        }
    }

    query.prepare(queryStr);

    // Bind values if searchText is not empty
    if (!searchText.isEmpty()) {
        QStringList searchParts = searchText.split(" ", Qt::SkipEmptyParts);
        if (searchParts.size() == 3) {
            query.bindValue(":firstName", "%" + searchParts[0] + "%");
            query.bindValue(":middleName", "%" + searchParts[1] + "%");
            query.bindValue(":lastName", "%" + searchParts[2] + "%");
        } else if (searchParts.size() == 2) {
            query.bindValue(":firstName", "%" + searchParts[0] + "%");
            query.bindValue(":lastName", "%" + searchParts[1] + "%");
        }
        query.bindValue(":searchText", "%" + searchText + "%");
    }

    if (!query.exec()) {
        qDebug() << "Query failed:" << query.lastError().text();
        return;
    }

    // Set the query results to the model
    model->setQuery(std::move(query));

    // Set the model to the QTableView
    ui->tableView->setModel(model);

    // Adjust column headers (optional)
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("First Name"));
    model->setHeaderData(2, Qt::Horizontal, tr("Middle Name"));
    model->setHeaderData(3, Qt::Horizontal, tr("Last Name"));
    model->setHeaderData(4, Qt::Horizontal, tr("Passport Number"));
    model->setHeaderData(5, Qt::Horizontal, tr("Contact Number"));
    model->setHeaderData(6, Qt::Horizontal, tr("Permanent Address"));
    model->setHeaderData(7, Qt::Horizontal, tr("Package Name"));
    model->setHeaderData(8, Qt::Horizontal, tr("Package Description"));

    // Adjust column widths (optional)
    ui->tableView->setColumnWidth(0, 100);
    ui->tableView->setColumnWidth(1, 120); // Set width for the first column
    ui->tableView->setColumnWidth(2, 120); // Set width for the second column
    ui->tableView->setColumnWidth(3, 120); // Set width for the third column
    ui->tableView->setColumnWidth(4, 150);
    ui->tableView->setColumnWidth(5, 150);
    ui->tableView->setColumnWidth(6, 350);
    ui->tableView->setColumnWidth(7, 150);
    ui->tableView->setColumnWidth(8, 350);

    database.close();
}
