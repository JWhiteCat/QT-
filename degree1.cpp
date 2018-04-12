#include "degree1.h"
#include "ui_degree1.h"

degree1::degree1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::degree1)
{
    ui->setupUi(this);
}

degree1::~degree1()
{
    delete ui;
}
