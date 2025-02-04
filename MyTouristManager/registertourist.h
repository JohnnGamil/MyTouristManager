#ifndef REGISTERTOURIST_H
#define REGISTERTOURIST_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class RegisterTourist;
}

class RegisterTourist : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterTourist(QWidget *parent = nullptr);
    ~RegisterTourist();

private slots:
    void on_btnSave_clicked();
    void onPackageSelected(int index); // Slot for handling package selection

    void on_btnReset_clicked();

private:
    Ui::RegisterTourist *ui;
    void populatePackageComboBox(); // Function to populate the ComboBox
};

#endif // REGISTERTOURIST_H
