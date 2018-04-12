#include "dialog1.h"
#include "ui_dialog1.h"
#include"mainwindow.h"

//
QPushButton *t;
QString tem;
const int N=3;
QPushButton *buttons[N*N];

//
void Swap(QPushButton *button1,QPushButton *button2);
QPushButton* FindHiddenButton();
bool IsNeighbor(QPushButton *button1,QPushButton *button2);
bool ResultIsOk();



Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);

    //初始化，产生所有按钮
    int w = 45;int i=0;
    for (int r = 0; r < N; r++)
    for (int c = 0; c < N; c++)
    {
        int num = r * N + c;
        QPushButton *btn=new QPushButton();
        btn->setText(QString::number(num + 1,10));
        btn->setFixedHeight(w);
        btn->setFixedWidth(w);
        btn->setStyleSheet("QPushButton{border-radius:5px;background:rgb(150, 190, 60);font-size:15px;}");
        buttons[i]=btn;
        buttons[i]->setProperty("tag",r * N + c); //这个数据用来表示它所在行列位置
        connect(buttons[i],SIGNAL(clicked()),this,SLOT(mySlot()));
        i++;
        ui->gridLayout->addWidget(btn,r,c);
    }
    buttons[N*N-1]->setVisible(false); //最后一个不可见

}

Dialog1::~Dialog1()
{
    delete ui;
}

void Dialog1::on_pushButton_clicked()
{
    MainWindow *w=new MainWindow();
    this->hide();
    w->show();
}

void Dialog1::on_pushButton_2_clicked()
{
    srand((unsigned)time(NULL));


    for(int i=0;i<100;i++)
    {
        int a=rand()%(N*N);
        int b=rand()%(N*N);
        Swap(buttons[a],buttons[b]);
    }
}

void Dialog1::mySlot()
{
    QPushButton *pre = (QPushButton*)sender();
    QPushButton *blank = FindHiddenButton();

    if(IsNeighbor(pre,blank))
    {
        Swap(pre,blank);
    }

    if(ResultIsOk())
    {
        QMessageBox::information(this,tr("恭喜"),tr("你赢了"));
    }
}

void Swap(QPushButton *button1,QPushButton *button2)
{
    bool v=button1->isVisible();
    button1->setVisible(button2->isVisible());
    button2->setVisible(v);
    tem=button1->text();
    button1->setText(button2->text());
    button2->setText(tem);
}

QPushButton* FindHiddenButton()
{

     for (int i = 0; i < N*N; i++)
    {
        if (!buttons[i]->isVisible())
        {
        return buttons[i];
        }
    }
    return 0;
}

bool IsNeighbor(QPushButton *button1,QPushButton *button2)
{
    int a = button1->property("tag").toInt(); //Tag中记录是行列位置
    int b = button2->property("tag").toInt();
    int r1 = a / N, c1 = a % N;
    int r2 = b / N, c2 = b % N;

    if ((r1 == r2 && (c1 == c2 - 1 || c1 == c2 + 1))|| (c1 == c2 && (r1 == r2 - 1 || r1 == r2 + 1)))
        return true;
    return false;
}

bool ResultIsOk()
{
    for(int i=0;i<N*N;i++)
    {
        if(buttons[i]->text().toInt()!=i+1)
            return false;
    }
    return true;
}








