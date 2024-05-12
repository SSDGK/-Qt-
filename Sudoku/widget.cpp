#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mPMap = nullptr;
    ui->startButton->setIcon(QIcon(":/icon/icon/startButton.png"));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::reshow()
{
    this->show();
}

void Widget::startGame(QString filenameA,QString filenameB)
{
    mPMap = new SudokuMap(filenameA,filenameB,this);
    bool key = mPMap->readMap(filenameA,filenameB);
    if(key)
    {
        GameWidget *gw = new GameWidget(mPMap);
        connect(gw,SIGNAL(gameEnd()),this,SLOT(reshow()));
        rule *rl = new rule;
        this->hide();
        gw->show();
        rl->show();
    }
    else
    {
        QMessageBox::warning(this,"读取出现问题","请重新读取");
    }
}

void Widget::on_startButton_clicked()
{
    QRandomGenerator rand;
    int file = rand.generate()%5+0;
    QString filenameA = QString(":/mapA/Map/MapA%1.txt").arg(file);
    QString filenameB = QString(":/mapB/Map/MapB%1.txt").arg(file);
    startGame(filenameA,filenameB);
}

