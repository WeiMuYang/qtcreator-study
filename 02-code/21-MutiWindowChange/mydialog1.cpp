#include "mydialog1.h"
#include "ui_mydialog1.h"

MyDialog1::MyDialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog1)
{
    ui->setupUi(this);
}

MyDialog1::~MyDialog1()
{
    delete ui;
}
