#include "Dialog3.h"
#include "ui_Dialog3.h"
#include"mainwindow.h"

//
QPushButton *t3;
QString tem3;
const int N3=8;
QPushButton *buttons3[N3*N3];
int flag3=0;

//
void Swap3(QPushButton *button1,QPushButton *buttoN3);
QPushButton* FindHiddenButton3();
bool IsNeighbor3(QPushButton *button1,QPushButton *buttoN3);
bool ResultIsOk3();



Dialog3::Dialog3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog3)
{
    ui->setupUi(this);

    //初始化，产生所有按钮
    int w = 45;int i=0;
    for (int r = 0; r < N3; r++)
    for (int c = 0; c < N3; c++)
    {
        int num = r * N3 + c;
        QPushButton *btn=new QPushButton();
        btn->setText(QString::number(num + 1,10));
        btn->setFixedHeight(w);
        btn->setFixedWidth(w);
        btn->setStyleSheet("QPushButton{border-radius:5px;background:rgb(150, 190, 60);font-size:15px;}");
        buttons3[i]=btn;
        buttons3[i]->setProperty("tag",r * N3 + c); //这个数据用来表示它所在行列位置
        connect(buttons3[i],SIGNAL(clicked()),this,SLOT(mySlot()));
        i++;
        ui->gridLayout->addWidget(btn,r,c);
    }
    buttons3[N3*N3-1]->setVisible(false); //最后一个不可见

}

Dialog3::~Dialog3()
{
    delete ui;
}

void Dialog3::on_pushButton_clicked()
{
    MainWindow *w=new MainWindow();
    this->hide();
    w->show();
}


void Dialog3::on_pushButton_2_clicked()
{
    flag3=1;
    int a,i;
    int b[4]={-N3,-1,1,N3};
    srand((unsigned)time(NULL));
    for(int j=0;j<3000;j++)
    {

        a = FindHiddenButton3()->property("tag").toInt();//Tag中记录是行列位置
        i=rand()%4;
        if(0<=a+b[i]&&a+b[i]<N3*N3)
            if(IsNeighbor3(FindHiddenButton3(),buttons3[a+b[i]]))
            Swap3(FindHiddenButton3(),buttons3[a+b[i]]);
    }
}

/*
void Dialog3::on_pushButton_2_clicked()
{
    srand((unsigned)time(NULL));
    for(int i=0;i<10000;i++)
    {
        int a=rand()%(N3*N3);
        if(IsNeighbor3(buttons3[a],FindHiddenButton3()))
            Swap3(buttons3[a],FindHiddenButton3());
    }
}
*/

void Dialog3::mySlot()
{
    QPushButton *pre = (QPushButton*)sender();
    QPushButton *blank = FindHiddenButton3();

    if(IsNeighbor3(pre,blank))
    {
        Swap3(pre,blank);
    }

    if(ResultIsOk3())
    {
        QMessageBox::information(this,tr("恭喜"),tr("你赢了"));
    }
}

void Swap3(QPushButton *button1,QPushButton *button3)
{
    bool v=button1->isVisible();
    button1->setVisible(button3->isVisible());
    button3->setVisible(v);
    tem3=button1->text();
    button1->setText(button3->text());
    button3->setText(tem3);
}

QPushButton* FindHiddenButton3()
{

     for (int i = 0; i < N3*N3; i++)
    {
        if (!buttons3[i]->isVisible())
        {
        return buttons3[i];
        }
    }
    return 0;
}

bool IsNeighbor3(QPushButton *button1,QPushButton *buttoN3)
{
    int a = button1->property("tag").toInt(); //Tag中记录是行列位置
    int b = buttoN3->property("tag").toInt();
    int r1 = a / N3, c1 = a % N3;
    int r2 = b / N3, c2 = b % N3;

    if ((r1 == r2 && (c1 == c2 - 1 || c1 == c2 + 1))|| (c1 == c2 && (r1 == r2 - 1 || r1 == r2 + 1)))
        return true;
    return false;
}

bool ResultIsOk3()
{
    if(flag3)
    {
        for(int i=0;i<N3*N3;i++)
        {
            if(buttons3[i]->text().toInt()!=i+1)
                return false;
        }
        return true;
    }
    return false;
}








