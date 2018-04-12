#include "Dialog2.h"
#include "ui_Dialog2.h"
#include"mainwindow.h"

//
QPushButton *t2;
QString tem2;
const int N2=4;
QPushButton *buttons2[N2*N2];

//
void Swap2(QPushButton *button1,QPushButton *button2);
QPushButton* FindHiddenButton2();
bool IsNeighbor2(QPushButton *button1,QPushButton *button2);
bool ResultIsOk2();



Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);

    //初始化，产生所有按钮
    int w = 45;int i=0;
    for (int r = 0; r < N2; r++)
    for (int c = 0; c < N2; c++)
    {
        int num = r * N2 + c;
        QPushButton *btn=new QPushButton();
        btn->setText(QString::number(num + 1,10));
        btn->setFixedHeight(w);
        btn->setFixedWidth(w);
        btn->setStyleSheet("QPushButton{border-radius:5px;background:rgb(150, 190, 60);font-size:15px;}");
        buttons2[i]=btn;
        buttons2[i]->setProperty("tag",r * N2 + c); //这个数据用来表示它所在行列位置
        connect(buttons2[i],SIGNAL(clicked()),this,SLOT(mySlot()));
        i++;
        ui->gridLayout->addWidget(btn,r,c);
    }
    buttons2[N2*N2-1]->setVisible(false); //最后一个不可见

}

Dialog2::~Dialog2()
{
    delete ui;
}

void Dialog2::on_pushButton_clicked()
{
    MainWindow *w=new MainWindow();
    this->hide();
    w->show();
}

void Dialog2::on_pushButton_2_clicked()
{
    srand((unsigned)time(NULL));


    for(int i=0;i<100;i++)
    {
        int a=rand()%(N2*N2);
        int b=rand()%(N2*N2);
        Swap2(buttons2[a],buttons2[b]);
    }
}

void Dialog2::mySlot()
{
    QPushButton *pre = (QPushButton*)sender();
    QPushButton *blank = FindHiddenButton2();

    if(IsNeighbor2(pre,blank))
    {
        Swap2(pre,blank);
    }

    if(ResultIsOk2())
    {
        QMessageBox::information(this,tr("恭喜"),tr("你赢了"));
    }
}

void Swap2(QPushButton *button1,QPushButton *button2)
{
    bool v=button1->isVisible();
    button1->setVisible(button2->isVisible());
    button2->setVisible(v);
    tem2=button1->text();
    button1->setText(button2->text());
    button2->setText(tem2);
}

QPushButton* FindHiddenButton2()
{

     for (int i = 0; i < N2*N2; i++)
    {
        if (!buttons2[i]->isVisible())
        {
        return buttons2[i];
        }
    }
    return 0;
}

bool IsNeighbor2(QPushButton *button1,QPushButton *button2)
{
    int a = button1->property("tag").toInt(); //Tag中记录是行列位置
    int b = button2->property("tag").toInt();
    int r1 = a / N2, c1 = a % N2;
    int r2 = b / N2, c2 = b % N2;

    if ((r1 == r2 && (c1 == c2 - 1 || c1 == c2 + 1))|| (c1 == c2 && (r1 == r2 - 1 || r1 == r2 + 1)))
        return true;
    return false;
}

bool ResultIsOk2()
{
    for(int i=0;i<N2*N2;i++)
    {
        if(buttons2[i]->text().toInt()!=i+1)
            return false;
    }
    return true;
}








