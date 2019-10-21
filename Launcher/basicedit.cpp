#include "basicedit.h"
#include "ui_basicedit.h"
#include <QMessageBox>

basicEdit::basicEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::basicEdit)
{
    ui->setupUi(this);
    conn.connOpen();
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("Select userid from owner where rank = '3' order by last ASC");

    qry->exec();
    modal->setQuery(*qry);
    ui->comboBox->setModel(modal);
}

basicEdit::~basicEdit()
{
    delete ui;
}

void basicEdit::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QString user= ui->comboBox->currentText();
    QSqlQuery qry;
    qry.prepare("select * from owner where userid ='"+user+"' and rank ='3'");
    if (qry.exec())
    {
        while(qry.next())
        {
            ui->firstEdit->setText(qry.value(1).toString());
            ui->lastEdit->setText(qry.value(2).toString());
            ui->emailEdit->setText(qry.value(3).toString());
            ui->phoneEdit->setText(qry.value(4).toString());
        }
    }
}

void basicEdit::on_pushButton_clicked()
{
    QString first;
    QString last;
    QString email;
    QString phone;

    QString user= ui->comboBox->currentText();
    QSqlQuery qry;

    first = ui->firstEdit->text();
    last = ui->lastEdit->text();
    email = ui->emailEdit->text();
    phone = ui->phoneEdit->text();

     qry.prepare("update owner set first = '"+first+"', last ='"+last+"', email = '"+email+"', phone = '"+phone+"' where userid = '"+user+"'");
     qry.exec();
     conn.connClose();
     QMessageBox::information(
     this,
     tr("Application Name"),
     tr("Edit to Customer Information Successful") );
     hide();
}
