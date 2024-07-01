#include "login.h"
#include "signup.h"
#include "bookretrival.h"
#include "mainwindow.h"
#include <QApplication>
#include <QMEssageBox>
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include "./ui_login.h"
using namespace std;
QString username;
login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_sign_in_clicked()
{
    username=ui->username->text();
    qDebug()<<username;
    QString password=ui->password->text();
    qDebug()<<password;
    QString  instruction="insert into user(username,password)values("+username+","+password+")";
    if(username.length()!=0&&password.length()!=0){
        QSqlQuery query;
        //QString str="select ";
        extern QSqlDatabase db;
        QSqlQuery q=db.exec("select name from reader where username='"+username+"'and password='"+password+"';");
        if(q.next()){
            QMessageBox::information(this,"","登录成功,欢迎");
            mainwindow * main=new mainwindow();//打开主窗口
            main->show();
            this->close();
        }
        else{
            QMessageBox::information(this,"","用户名不存在或密码错误");
        }
    }
    else{
        QMessageBox::information(this,"","用户名或密码为空");
    }
}


void login::on_sign_up_clicked()
{
    bookRetrival *bk=new bookRetrival();
    bk->show();
}

