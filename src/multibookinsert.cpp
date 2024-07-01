#include "multibookinsert.h"
#include "ui_multibookinsert.h"
#include <QCoreApplication>
#include <QDebug>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QStringList>
#include <QSqlQuery>

multibookinsert::multibookinsert(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::multibookinsert)
{
    ui->setupUi(this);
}

multibookinsert::~multibookinsert()
{
    delete ui;
}

void multibookinsert::on_fileimport_clicked()
{
    QString filepath= QFileDialog::getOpenFileName(this,"上传文件","D:/",tr("文本文件(*.txt *.csv);;所有文件(*.*)"));
    if (filepath.isEmpty()) {
        QMessageBox::warning(this, "Warning!", "Failed to open the text file!");
    }
    else {
        QFile file(filepath);
        int index;
        ui->resulttable->clearContents();
        file.open(QFileDevice::ReadOnly);
        while(!file.atEnd()){
            index=ui->resulttable->rowCount();
            ui->resulttable->insertRow(index);//增加一行
            QString row=file.readLine().trimmed();
            QStringList data=row.split(',');
            QString ISBN=data[0];
            QString category=data[1];
            QString language=data[2];
            QString bookname=data[3];
            QString author=data[4];
            QString price=data[5];
            QString press=data[7];
            QString public_year=data[6];
            QString storenumber=data[8];
            QString current_num=data[8];
            //QString update_time=QDateTime::currentDateTime().toString();
            //ui->borrowdate->setText(update_time);
            ui->resulttable->setItem(index,0,new QTableWidgetItem(ISBN));
            ui->resulttable->setItem(index,1,new QTableWidgetItem(bookname));
            ui->resulttable->setItem(index,2,new QTableWidgetItem(author));
            ui->resulttable->setItem(index,3,new QTableWidgetItem(category));
            ui->resulttable->setItem(index,4,new QTableWidgetItem(press));
            ui->resulttable->setItem(index,5,new QTableWidgetItem(language));
            ui->resulttable->setItem(index,6,new QTableWidgetItem(public_year));
            ui->resulttable->setItem(index,7,new QTableWidgetItem(price));
            ui->resulttable->setItem(index,8,new QTableWidgetItem(storenumber));
            ui->resulttable->setItem(index,9,new QTableWidgetItem(current_num));
        }
        qDebug()<<index;
    }
}


void multibookinsert::on_multipleinsert_clicked()
{   int cnt=0;
    QSqlQuery sql;
    QString ISBN,category,language,bookname,author,price,press,public_year,store_num,current_num;
    for(int i=0;i<ui->resulttable->rowCount();i++){
         ISBN=ui->resulttable->item(i,0)->text();
         bookname=ui->resulttable->item(i,1)->text();
         category=ui->resulttable->item(i,3)->text();
         language=ui->resulttable->item(i,5)->text();
         author=ui->resulttable->item(i,2)->text();
         price=ui->resulttable->item(i,7)->text();
         press=ui->resulttable->item(i,4)->text();
         public_year=ui->resulttable->item(i,6)->text();
         store_num=ui->resulttable->item(i,8)->text();
         current_num=ui->resulttable->item(i,9)->text();
         //qDebug()<<ISBN+category+language+bookname+author+price+press+public_year;
         QString query1=QString("insert into book(bookname,author,ISBN,press,language,category,public_year,store_num,price,current_num) values('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10')").arg(bookname).arg(author).arg(ISBN).arg(press).arg(language).arg(category).arg(public_year).arg(store_num).arg(price).arg(current_num);
          qDebug()<<query1;
          bool ok=sql.exec(query1);
         if(ok){
              cnt++;
         }
        else{
        //     qDebug()<<cnt;
         }
    }
    if(cnt){
        char  buffer[20];
       printf(buffer,"共入库成功%d本",cnt);
        QMessageBox::information(NULL,"",buffer);
    }
    ui->fileimport->hide();
}

void multibookinsert::on_clear_clicked()
{
    ui->resulttable->clearContents();
    ui->resulttable->setRowCount(0);
    ui->fileimport->show();
}

