#include "mainwindow.h"
#include "insertbook.h"
#include "ui_mainwindow.h"
#include "bookretrival.h"
#include "borrowcard.h"
#include "checkborrowed.h"
#include "borrowbook.h"
#include "backbook.h"
#include "login.h"
#include "multibookinsert.h"
#include "signup.h"
mainwindow::mainwindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mainwindow)
{
    ui->setupUi(this);
}

mainwindow::~mainwindow()
{
    delete ui;
}

void mainwindow::on_bookadd_currentIndexChanged(int index)
{
    if(ui->bookadd->currentIndex()==0||ui->bookadd->currentIndex()==1){
        InsertBook *ib=new InsertBook;
        ib->show();
    }
    else{
        multibookinsert *mb=new multibookinsert;
        mb->show();
    }
}


void mainwindow::on_bookretrival_clicked()
{
    bookRetrival * br=new bookRetrival;
    br->show();
}


void mainwindow::on_borrowcard_clicked()
{
    borrowCard * bc=new borrowCard;
    bc->show();
}


void mainwindow::on_borrow_currentIndexChanged(int index)
{
    checkborrowed *cb;
    borrowbook *bb;
    backbook *bb1;
    switch(ui->borrow->currentIndex()){
    case 1: cb=new checkborrowed;cb->show();break;
    case 2: bb=new borrowbook;bb->show();break;
    case 3: bb1=new backbook;bb1->show();break;
    }

}


void mainwindow::on_admin_currentIndexChanged(int index)
{
    signup *sp;
    switch(ui->admin->currentIndex()){
    case 1: sp=new signup;sp->show();break;
    case 2:break;
    }
}


void mainwindow::on_exitlogin_clicked()
{
    login *ln=new login;
    ln->show();
    this->close();
}

