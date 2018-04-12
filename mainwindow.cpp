#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_4_clicked()
{
    QMessageBox::information(this,tr("游戏规则"),tr("点击开始，将数字还原为原来的位置"));
}

void MainWindow::on_pushButton_clicked()
{
    Dialog1 *d=new Dialog1();
    this->hide();
    d->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    Dialog2 *d=new Dialog2();
    this->hide();
    d->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    Dialog3 *d=new Dialog3();
    this->hide();
    d->show();
}
