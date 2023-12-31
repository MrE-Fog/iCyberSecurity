#ifndef VIEWDATABASE_H
#define VIEWDATABASE_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class viewDatabase;
}

class viewDatabase : public QDialog
{
    Q_OBJECT

public:
    explicit viewDatabase(QWidget *parent = nullptr);
    ~viewDatabase();
public:
    MainWindow conn;

private slots:
    void on_loadDatabase_clicked();

    void on_loadDatabase_2_clicked();

    void on_loadDatabase_3_clicked();

    void on_loadDatabase_4_clicked();

    void on_loadDatabase_5_clicked();

    void on_loadDatabase_6_clicked();

private:
    Ui::viewDatabase *ui;
};

#endif // VIEWDATABASE_H
