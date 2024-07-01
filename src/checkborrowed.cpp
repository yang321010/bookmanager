#include "checkborrowed.h"
#include "ui_checkborrowed.h"
#include <QCoreApplication>
#include <QSqlQuery>
#include <QDebug>

checkborrowed::checkborrowed(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::checkborrowed)
{
    ui->setupUi(this);
}

checkborrowed::~checkborrowed()
{
    delete ui;
}

void checkborrowed::on_lineEdit_textChanged(const QString &arg1)
{
    QString query=QString("select * from book,libraryrecord where book.ISBN=libraryrecord.ISBN and libraryrecord.CardNo='%1'").arg(arg1);
    qDebug()<<query;
    QSqlQuery sql(query);
    int index;
    ui->resulttable->clearContents();
    ui->resulttable->setRowCount(0);
    while(sql.next()){
        index=ui->resulttable->rowCount();
        ui->resulttable->insertRow(index);//增加一行
        QString ISBN=sql.value(0).toString();
        QString category=sql.value(1).toString();
        QString bookname=sql.value(3).toString();
        QString author=sql.value(4).toString();
        QString price=sql.value(5).toString();
        QString press=sql.value(6).toString();
        QString public_year=sql.value(7).toString();
        QString storenumber=sql.value(8).toString();
        QString current_num=sql.value(9).toString();
        QString lentdate=sql.value(12).toString();
        ui->resulttable->setItem(index,0,new QTableWidgetItem(lentdate));
        ui->resulttable->setItem(index,1,new QTableWidgetItem(ISBN));
        ui->resulttable->setItem(index,2,new QTableWidgetItem(bookname));
        ui->resulttable->setItem(index,3,new QTableWidgetItem(author));
        ui->resulttable->setItem(index,4,new QTableWidgetItem(category));
        ui->resulttable->setItem(index,5,new QTableWidgetItem(press));
        ui->resulttable->setItem(index,6,new QTableWidgetItem(public_year));
        ui->resulttable->setItem(index,7,new QTableWidgetItem(price));
        ui->resulttable->setItem(index,8,new QTableWidgetItem(storenumber));
        ui->resulttable->setItem(index,9,new QTableWidgetItem(current_num));
    }
}

