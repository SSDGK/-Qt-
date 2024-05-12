#include "gamewin.h"
#include "ui_gamewin.h"

GameWin::GameWin(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameWin)
{
    ui->setupUi(this);
    QRandomGenerator rand;
    int pic = rand.generate()%2+0;
    ui->toolButton->setIcon(QIcon(QString(":/icon/icon/winicon%1.jpg").arg(pic)));
}

GameWin::~GameWin()
{
    delete ui;
}
