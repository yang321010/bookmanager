#include "borrowcard.h"
#include "ui_borrowcard.h"
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDateTime>
#include <QMessageBox>

borrowCard::borrowCard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::borrowCard)
{
    ui->setupUi(this);
}

borrowCard::~borrowCard()
{
    delete ui;
}

void borrowCard::on_add_clicked()
{

    QString cardnum=ui->cardnum->text();
    QString department=ui->department->text();
    QString name=ui->name->text();
   // qDebug()<<updatetime;
    QString cardtype;
    switch(ui->cardtype->currentIndex()){
    case 1:cardtype="teacher";break;
    case 2:cardtype="student";break;
    }
    if(cardnum.trimmed()==""||department.trimmed()==""||name.trimmed()==""||cardtype.trimmed()==""){
        QMessageBox::information(NULL,"","不能为空");
    }
    else{
        QDateTime updatetime=QDateTime::currentDateTime();//
    QString query=QString("insert into LibraryCard(CardNo,Name,Department,CardTpye,UpdateTime)values('%1','%2','%3','%4',%5)").arg(cardnum).arg(name).arg(department).arg(cardtype).arg(updatetime.toString("yyyyMMddhhmmss"));
    qDebug()<<query;
    QSqlQuery sql;
    bool ok=sql.exec(query);
    if(ok){
        ui->updatetime->setText(updatetime.toString("yyyy/MM/dd/ hh:mm:ss"));
        //QMessageBox::information(NULL,"","成功插入");
    }
    else{
        ui->updatetime->setText("插入错误，请重试！");
    }
    }

}


void borrowCard::on_delete_2_clicked()
{
    QString query="delete from LibraryCard where CardNo='"+ ui->cardnum->text()+"';";
    QSqlQuery sql;
    bool ok=sql.exec(query);
    if(ok){
        QMessageBox::information(NULL,"","删除借书证成功！");
    }
    else{
        QMessageBox::information(NULL,"","删除借书证失败！");
    }
}

