#include "login.h"
#include "signup.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QApplication>
#include <QMEssageBox>
QSqlDatabase db;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login w;
    w.show();
    qDebug()<<QSqlDatabase::drivers();
    db = QSqlDatabase::addDatabase("QMYSQL");//声明数据库对象
    db.setHostName("127.0.0.1");  //本地主机号
    db.setDatabaseName("bookmanger");//数据库名
    db.setPort(3306);
    db.setUserName("root"); //数据库账号
    db.setPassword("YXL139159");//数据库密码，就是安装mysql时你设置的密码
    //db.exec("SET NAMES 'GB2312'"); //编码格式GB2312
    bool ok=db.open(); //打开数据库
    if (ok){
        QMessageBox::information(NULL, "MySQL_infor", "success");
    }
    else {
        QMessageBox::information(NULL, "MySQL_infor", "open failed");
        qDebug()<< db.lastError();
    }
    return a.exec();
}
