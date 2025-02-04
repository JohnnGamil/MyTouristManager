#ifndef ADDPACKAGE_H
#define ADDPACKAGE_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class AddPackage;
}

class AddPackage : public QDialog
{
    Q_OBJECT

public:
    explicit AddPackage(QWidget *parent = nullptr);
    ~AddPackage();

private slots:
    void on_bntSave_clicked();

    void on_bntReset_clicked();

private:
    Ui::AddPackage *ui;
};

#endif // ADDPACKAGE_H
