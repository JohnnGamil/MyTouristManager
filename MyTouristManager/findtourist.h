#ifndef FINDTOURIST_H
#define FINDTOURIST_H

#include <QDialog>
#include "databaseheader.h"
#include <QSqlQueryModel>

namespace Ui {
class FindTourist;
}

class FindTourist : public QDialog
{
    Q_OBJECT

public:
    explicit FindTourist(QWidget *parent = nullptr);
    ~FindTourist();

private slots:
    void on_btnFind_clicked();

private:
    Ui::FindTourist *ui;
    QSqlQueryModel *model; // Model for displaying query results
    void setupAutoComplete();
    void loadAllTourists();
};

#endif // FINDTOURIST_H
