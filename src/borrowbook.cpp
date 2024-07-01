#include "borrowbook.h"
#include "ui_borrowbook.h"
#include "QSqlDatabase"
#include <QSqlQuery>
#include "QMessageBox"
#include "QCoreApplication"
#include "QDebug"
#include <QDatetime>
extern   QString username;
borrowbook::borrowbook(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::borrowbook)
{
    ui->setupUi(this);
}

borrowbook::~borrowbook()
{
    delete ui;
}




void borrowbook::on_borrow_clicked()
{   QString ISBN=ui->ISBN->text();
    QString borrowcard=ui->borrowcard->text();
    QString currentdatetime=QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
    QString query2=QString("insert into LibraryRecord(ISBN,CardNo,lentdate,operator) values('%1','%2',%3,'%4')").arg(ISBN).arg(borrowcard).arg(currentdatetime).arg(username);
    QString query=QString("update book set current_num= current_num-1 where ISBN='%1'and current_num>=1").arg(ISBN);
    QSqlQuery sql;
    int isISBNvalid=0,iscardvalid=0,isborrowed=0;
    QString current_num;//记录当前图书数量是否为0
    if(sql.exec("select * from book where ISBN='"+ISBN+"';")){
        isISBNvalid=1;
        sql.next();
        current_num=sql.value("current_num").toString();
    }
    else{
        isISBNvalid=0;
    }
    if(sql.exec("select * from librarycard where CardNo='"+borrowcard+"';")){
        iscardvalid=1;
    }
    else{
        isISBNvalid=0;
    }
    sql.exec("select * from libraryrecord where CardNo='"+borrowcard+"'and ISBN='"+ISBN+"';");
    if(sql.next()){
        isborrowed=1;
    }
    qDebug()<<isborrowed;
    qDebug()<<query2;
    if(isISBNvalid&&iscardvalid&&!isborrowed&&current_num.toInt()){
        bool ok=sql.exec(query);
        if(ok){
            QMessageBox::information(NULL,"","借书成功");
            on_lookstore_clicked();
            ui->borrowdate->setText(currentdatetime);

        }
        else{
            QMessageBox::information(NULL,"","借书失败");
        }
        if(sql.exec(query2)){
            QMessageBox::information(NULL,"","插入成功");
        }
        else{
            QMessageBox::information(NULL,"","借书失败");
        }

    }

}


void borrowbook::on_lookstore_clicked()
{
    QString ISBN=ui->ISBN->text();
    QString query=QString("select * from book where ISBN='%1'").arg(ISBN);
    qDebug()<<query;
    QSqlQuery sql(query);
    int flag=0;
    int index;
    ui->resulttable->clearContents();
    ui->resulttable->setRowCount(0);
    while(sql.next()){
        flag=1;
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
        QString update_time=QDateTime::currentDateTime().toString();
        ui->borrowdate->setText(update_time);
        ui->resulttable->setItem(index,0,new QTableWidgetItem(ISBN));
        ui->resulttable->setItem(index,1,new QTableWidgetItem(bookname));
        ui->resulttable->setItem(index,2,new QTableWidgetItem(category));
        ui->resulttable->setItem(index,3,new QTableWidgetItem(author));
        ui->resulttable->setItem(index,4,new QTableWidgetItem(press));
        ui->resulttable->setItem(index,5,new QTableWidgetItem(language));
        ui->resulttable->setItem(index,6,new QTableWidgetItem(public_year));
        ui->resulttable->setItem(index,7,new QTableWidgetItem(storenumber));
        ui->resulttable->setItem(index,8,new QTableWidgetItem(price));
        ui->resulttable->setItem(index,9,new QTableWidgetItem(current_num));
            //index++;
            //ui->resulttable->setRowCount(index);
    }
    if(!flag){
        QMessageBox::information(NULL,"","没有找到该书！");
    }
}

