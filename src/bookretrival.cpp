#include "bookretrival.h"
#include "borrowbook.h"
#include "ui_bookretrival.h"
#include "QApplication"
#include <QMEssageBox>
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QStringList>

bookRetrival::bookRetrival(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::bookRetrival)
{
    ui->setupUi(this);
}

bookRetrival::~bookRetrival()
{
    delete ui;
}

void bookRetrival::on_retrival2_clicked()
{
    QString str;
    switch(ui->searchindex->currentIndex()){
    case 1:  str="bookname";break;
    case 2:  str="author";break;
    case 3:  str="press";break;
    case 4:  str="public_year";break;
    case 5:  str="category";break;
    }

    QString query=QString("select * from book where %1 like '\%%2\%'").arg(str).arg(ui->queryword->text());
    qDebug()<<query;
    QSqlQuery sql(query);
    int index=0;
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
    }
}


void bookRetrival::on_retirval1_clicked()
{
    QString str;
    switch(ui->searchindex->currentIndex()){
    case 1:  str="bookname";break;
    case 2:  str="author";break;
    case 3:  str="press";break;
    case 4:  str="public_year";break;
    case 5:  str="category";break;
    }

    QString query=QString("select * from book where %1='%2'").arg(str).arg(ui->queryword->text());
    qDebug()<<query;
    QSqlQuery sql(query);
    int index=0;
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
}


void bookRetrival::on_pushButton_clicked()
{
    borrowbook * bb=new borrowbook();
    bb->show();
}


void bookRetrival::on_search_clicked()
{   QString bookname=ui->bookname->text();
    QString author=ui->author->text();
    QString low_price=ui->low_price->text();
    QString high_price=ui->high_price->text();
    QString low_year=ui->low_year->text();
    QString high_year=ui->high_year->text();
    QString press;
    switch(ui->press->currentIndex()){
    case 0: press="press";break;
    case 1: press="电子工业出版社";break;
    case 2: press="人民邮电出版社";break;
    case 3: press="机械工业出版社";break;
    case 4: press="其他";break;
    }
    if(low_price.length()==0){
        low_price="0";
    }
    if(high_price.length()==0){
        high_price="1000";
    }
    if(low_year.length()==0){
        low_year="0";
    }
    if(high_year.length()==0){
        high_year="2500";
    }
    QString category;
    QStringList categories={"category","工学","理学","文学","医学","农学","交叉学科","经济学","管理学","教育学","哲学","法学","艺术学","历史学"};
    category=categories[ui->category->currentIndex()];
    QString query=QString("select * from book where bookname like '%%1%'and author like '%%2%' and price>=%3 and price<=%4 and category='%5' and press='%6' and public_year>=%7 and public_year<=%8").arg(bookname).arg(author).arg(low_price).arg(high_price).arg(category).arg(press).arg(low_year).arg(high_year);
    if(press=="press"){
        query.replace("'press'","press");
    }
    if(press=="其他"){
        query.replace("press='其他'","press !='电子工业出版社' and press !='人民邮电出版社' and press !='机械工业出版社'");
    }
    if(category=="category"){
        query.replace("'category'","category");
    }
    qDebug()<<query;
    int index;
    ui->resulttable->clearContents();
   ui->resulttable->setRowCount(0);
    QSqlQuery sql(query);
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
    }
}

