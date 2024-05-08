#include "gamewidget.h"
#include "ui_gamewidget.h"

GameWidget::GameWidget(SudokuMap *mPMap,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameWidget)
{
    ui->setupUi(this);
    makeMap(mPMap);
}

GameWidget::~GameWidget()
{
    delete ui;
}

void GameWidget::on_pushButton_clicked()
{
    this->close();
}

void GameWidget::makeMap(SudokuMap *mPMap)
{


};
