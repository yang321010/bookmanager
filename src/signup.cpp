#include "signup.h"
#include "login.h"
#include "ui_signup.h"
#include <QCoreApplication>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

signup::signup(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::signup)
{
    ui->setupUi(this);
}

signup::~signup()
{
    delete ui;
}
void signup::on_buttonBox_accepted()
{
    QString username=ui->usename1->text();
    QString password=ui->password1->text();
    QString name1=ui->name1->text();
    QString contact=ui->contact->text();
    QString job;
    if(ui->isteacher->isChecked()){
        job="teacher";
    }
    if(ui->isstudent->isChecked()){
        job="student";
    }
    QSqlQuery query;
    if(username==""||password==""||name1==""||job==""||contact==""){
        if(username==""||password==""||name1==""||contact==""){
        QMessageBox::information(NULL,"","字段不能为空");
        }
        else{
        QMessageBox::information(NULL,"","请勾选您的职业");
}
    }
    else{
        QString query2="select * from reader where username='"+username+"'";
        if(query.exec(query2)){
            QMessageBox::information(NULL,"","用户已存在");
        }
        else{
            QString query1="insert into reader(username,password,name,job，contact) values('"+username+"','"+password+"','"+name1+"','"+job+"'"+contact+"');";
            if(query.exec(query1)){
                QMessageBox::information(NULL,"","register secessfully");
            }
            else{
                QMessageBox::information(NULL,"","failed");
            }
        }
    }
    login * p=new login();
    p->show();

}



void signup::on_buttonBox_rejected()
{
    login * p=new login();
    p->show();
}

