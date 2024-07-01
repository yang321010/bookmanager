#include "backbook.h"
#include "ui_backbook.h"
#include <QCoreApplication>
#include <QSqlQuery>
#include <QDebug>
#include <QDateTime>
#include <QMessageBox>

backbook::backbook(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::backbook)
{
    ui->setupUi(this);
}

backbook::~backbook()
{
    delete ui;
}

void backbook::on_CardNo_textChanged(const QString &arg1)
{
    QString query=QString("select * from book,libraryrecord where book.ISBN=libraryrecord.ISBN and libraryrecord.CardNo='%1'and libraryrecord.returndate is NULL").arg(arg1);
    qDebug()<<query;
    QString query2=QString("select * from librarycard where CardNo = '%1'").arg(arg1);
    QSqlQuery sql(query2);
    QString department,job,name1;
    if(sql.next()){
        department=sql.value("Department").toString();
        job=sql.value("CardTpye").toString();
        name1=sql.value("Name").toString();
    }
    ui->Department->setText(department);
    ui->Name->setText(name1);
    ui->job->setText(job);
    sql.exec(query);
    int index;
    ui->resulttable->clearContents();
    ui->resulttable->setRowCount(0);
    while(sql.next()){
        index=ui->resulttable->rowCount();
        ui->resulttable->insertRow(index);//增加一行
        QString ISBN=sql.value(0).toString();
        QString category=sql.value(1).toString();
        QString language=sql.value(2).toString();
        QString bookname=sql.value(3).toString();
        QString author=sql.value(4).toString();
        QString price=sql.value(5).toString();
        QString press=sql.value(6).toString();
        QString public_year=sql.value(7).toString();
        QString storenumber=sql.value(8).toString();
        QString current_num=sql.value(9).toString();
        QString lentdate=sql.value(12).toString();
        //QString update_time=QDateTime::currentDateTime().toString();
        //ui->borrowdate->setText(update_time);
        ui->resulttable->setItem(index,0,new QTableWidgetItem(lentdate));
        ui->resulttable->setItem(index,1,new QTableWidgetItem(ISBN));
        ui->resulttable->setItem(index,2,new QTableWidgetItem(bookname));
        ui->resulttable->setItem(index,3,new QTableWidgetItem(author));
        ui->resulttable->setItem(index,4,new QTableWidgetItem(category));
        ui->resulttable->setItem(index,5,new QTableWidgetItem(press));
        //ui->resulttable->setItem(index,5,new QTableWidgetItem(language));
        ui->resulttable->setItem(index,6,new QTableWidgetItem(public_year));
        ui->resulttable->setItem(index,7,new QTableWidgetItem(price));
        ui->resulttable->setItem(index,8,new QTableWidgetItem(storenumber));
        ui->resulttable->setItem(index,9,new QTableWidgetItem(current_num));
        //index++;
    }
}


void backbook::on_pushButton_clicked()
{
    QString ISBN=ui->ISBN->text();
    QString CardNo=ui->CardNo->text();
    QString datetime=QDateTime::currentDateTime().toString("yyyyMMddhhmmss");

    QString str=QString("update libraryrecord set returndate='%1' where ISBN='%2' and CardNo='%3'and returndate is NULL").arg(datetime).arg(ISBN).arg(CardNo);
    qDebug()<<str;
    QString str2=QString("update book set current_num= current_num+1 where ISBN='%1'").arg(ISBN);
    QSqlQuery sql;
    qDebug()<<str2;
    if(sql.exec(str)){
        on_CardNo_textChanged(ui->ISBN->text());
        if(sql.exec(str2)){
            QMessageBox::information(NULL,"","还书成功！");
        }
        else{
            QMessageBox::information(NULL,"","更新失败，严重错误");
        }
    }
    else{
        QMessageBox::information(NULL,"","还书失败！");
    }
}

