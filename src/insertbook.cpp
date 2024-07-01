#include "insertbook.h"
#include "ui_insertbook.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>

InsertBook::InsertBook(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InsertBook)
{
    ui->setupUi(this);
}

InsertBook::~InsertBook()
{
    delete ui;
}

void InsertBook::on_pushButton_clicked()
{
    QString bookname=ui->bookname->text();
    qDebug()<<bookname;
    //QString ISBN=ui->ISBN->text();
    QString press=ui->press->text();
    QString ISBN=ui->ISBN->text();
    int public_year=ui->PY->text().toInt();
    QString category=ui->category->text();
    QString author=ui->author->text();
    QString language=ui->language->text();
    double price=ui->price->text().toDouble();
    int number=ui->number->text().toInt();
    QSqlQuery query;
    QString query1=QString("insert into book(bookname,author,ISBN,press,language,category,public_year,store_num,price,current_num) values('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10')").arg(bookname).arg(author).arg(ISBN).arg(press).arg(language).arg(category).arg(public_year).arg(number).arg(price).arg(number);
    qDebug()<<query1;
    bool ok=query.exec(query1);
    if(ok){
        QMessageBox::information(this,"","入库成功！！");
    }
    else{
        QMessageBox::information(this,"","抱歉，入库失败");
    }
}

