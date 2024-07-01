#include "borrowwatch.h"
#include "ui_borrowwatch.h"

borrowWatch::borrowWatch(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::borrowWatch)
{
    ui->setupUi(this);
}

borrowWatch::~borrowWatch()
{
    delete ui;
}
