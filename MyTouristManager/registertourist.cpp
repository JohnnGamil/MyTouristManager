#include "registertourist.h"
#include "ui_registertourist.h"

RegisterTourist::RegisterTourist(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::RegisterTourist)
{
    ui->setupUi(this);
    this->setStyleSheet("QDialog {"
                        "    background-image: url(:/res/StateOfLibery5.jpg);"
                        "    background-position: center;"
                        "    background-repeat: no-repeat;"
                        "    background-attachment: fixed;"
                        "    background-size: cover;"
                        "}");

    // Populate the ComboBox with PackageName values
    populatePackageComboBox();

    // Set the first item in the ComboBox as the default selected item
    if (ui->cmbChoosePackage->count() > 0) {
        ui->cmbChoosePackage->setCurrentIndex(0); // Select the first item
        onPackageSelected(0); // Retrieve and display the description for the first item
    }

    // Connect the ComboBox's currentIndexChanged signal to the slot
    connect(ui->cmbChoosePackage, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &RegisterTourist::onPackageSelected);
}

RegisterTourist::~RegisterTourist()
{
    delete ui;
}

void RegisterTourist::populatePackageComboBox() {
    QSqlDatabase database = QSqlDatabase::database(); // Reuse existing connection
    if (!database.isOpen()) {
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("F:/MyTouristManager/MyTouristManager.db");
        if (!database.open()) {
            qDebug() << "Error: Unable to open Database";
            return;
        }
    }

    QSqlQuery query(database);
    query.prepare("SELECT PackageName FROM Package");

    if (!query.exec()) {
        qDebug() << "Query failed:" << query.lastError().text();
        return;
    }

    // Clear the ComboBox before populating it
    ui->cmbChoosePackage->clear();

    // Populate the ComboBox with PackageName values
    while (query.next()) {
        QString packageName = query.value("PackageName").toString();
        ui->cmbChoosePackage->addItem(packageName);
    }

    database.close();
}

void RegisterTourist::onPackageSelected(int index) {
    QString packageName = ui->cmbChoosePackage->itemText(index); // Get the selected package name

    QSqlDatabase database = QSqlDatabase::database(); // Reuse existing connection
    if (!database.isOpen()) {
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("F:/MyTouristManager/MyTouristManager.db");
        if (!database.open()) {
            qDebug() << "Error: Unable to open Database";
            return;
        }
    }

    QSqlQuery query(database);
    query.prepare("SELECT PackageDescription FROM Package WHERE PackageName = :packageName");
    query.bindValue(":packageName", packageName);

    if (!query.exec()) {
        qDebug() << "Query failed:" << query.lastError().text();
        return;
    }

    if (query.next()) {
        QString packageDescription = query.value("PackageDescription").toString();
        ui->txtPackageDescription->setPlainText(packageDescription); // Display the description
    }

    database.close();
}

void RegisterTourist::on_btnSave_clicked() {
    QString firstName = ui->txtFirstName->text();
    QString middleName = ui->txtMiddleName->text();
    QString lastName = ui->txtLastName->text();
    QString passportNo = ui->txtPassportNo->text();
    QString contactNo = ui->txtContactNo->text();
    QString permanentAddress = ui->txtPermanentAddress->text();
    QString packageName = ui->cmbChoosePackage->currentText();
    QString packageDescription = ui->txtPackageDescription->toPlainText(); // Retrieve the description

    // Validate required fields
    if (firstName.isEmpty() || passportNo.isEmpty() || permanentAddress.isEmpty()) {
        qDebug() << "Error: Required fields are empty";
        return;
    }

    // Reuse the existing database connection
    QSqlDatabase database = QSqlDatabase::database(); // No need to call addDatabase again

    if (!database.isOpen()) {
        qDebug() << "Error: Database is not open";
        return;
    }

    QSqlQuery query(database);
    query.prepare("INSERT INTO Tourist (FirstName, MiddleName, LastName, PassportNo, ContactNo, PermanentAddress, PackageName, PackageDescription) "
                  "VALUES (:firstName, :middleName, :lastName, :passportNo, :contactNo, :permanentAddress, :packageName, :packageDescription)");
    query.bindValue(":firstName", firstName);
    query.bindValue(":middleName", middleName);
    query.bindValue(":lastName", lastName);
    query.bindValue(":passportNo", passportNo);
    query.bindValue(":contactNo", contactNo);
    query.bindValue(":permanentAddress", permanentAddress);
    query.bindValue(":packageName", packageName);
    query.bindValue(":packageDescription", packageDescription); // Bind the description

    // Debugging: Print the query and values
    qDebug() << "Executing query:" << query.lastQuery();
    qDebug() << "Values:"
             << "firstName:" << firstName
             << "middleName:" << middleName
             << "lastName:" << lastName
             << "passportNo:" << passportNo
             << "contactNo:" << contactNo
             << "permanentAddress:" << permanentAddress
             << "packageName:" << packageName
             << "packageDescription:" << packageDescription;

    if (!query.exec()) {
        qDebug() << "Last Error: " << query.lastError().text();
    } else {
        qDebug() << "Tourist registered successfully!";
    }
}

void RegisterTourist::on_btnReset_clicked()
{
    ui->txtFirstName->clear();
    ui->txtMiddleName->clear();
    ui->txtLastName->clear();
    ui->txtPassportNo->clear();
    ui->txtContactNo->clear();
    ui->txtPermanentAddress->clear();

}

