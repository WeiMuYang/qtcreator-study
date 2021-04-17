#include "myframe1.h"
#include "ui_myframe1.h"

MyFrame1::MyFrame1(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::MyFrame1)
{
    ui->setupUi(this);
}

MyFrame1::~MyFrame1()
{
    delete ui;
}
