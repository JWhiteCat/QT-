# QTNumerity
程序简介：
	用QT实现了一个数字拼图：
1.	QMessageBox显示提示信息。
2.	可以选择难度，程序有切换窗口的功能。
3.	写了一点点CSS样式。
4.  单实例运行。

对于打乱拼图的算法，我一共写出了三种
第一种：无脑随机，可能会出现无解的情况，且可能性较大。

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

第二种：随机抽取一块拼图，判断其与空白拼图是否相邻，若相邻，则交换。这种方法在N很大时需要较多的循环次数

void Dialog1::on_pushButton_2_clicked()
{

    srand((unsigned)time(NULL));
    for(int i=0;i<2000;i++)
    {
        int a=rand()%(N*N);
        if(IsNeighbor(buttons[a],FindHiddenButton()))
            Swap(buttons[a],FindHiddenButton());
    }
}

第三种：空白拼图随机交换一块与之相邻的拼图。仅需要较少的循环次数

void Dialog1::on_pushButton_2_clicked()
{

    int a,i;
    int b[4]={-N,-1,1,N};
    srand((unsigned)time(NULL));
    for(int j=0;j<3000;j++)
    {
        a = FindHiddenButton()->property("tag").toInt();
        i=rand()%4;
        if(0<=a+b[i]&&a+b[i]<N*N)
            if(IsNeighbor(FindHiddenButton(),buttons[a+b[i]]))
            Swap(FindHiddenButton(),buttons[a+b[i]]);
    }
}
