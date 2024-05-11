#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mPMap = nullptr;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_loadButton_clicked()
{

    QString filenameA = QFileDialog::getOpenFileName(this,"选择地图文件A","F:\\QtProject\\Sudoku\\Map");
    QString filenameB = QFileDialog::getOpenFileName(this,"选择地图文件B","F:\\QtProject\\Sudoku\\Map");
    mPMap = new SudokuMap(filenameA,filenameB,this);
    bool key = mPMap->readMap(filenameA,filenameB);
    if(key)
    {
        GameWidget *gw = new GameWidget(mPMap);
        gw->show();
        this->hide();
    }
    else
    {
        QMessageBox::warning(this,"读取出现问题","请重新读取");
    }
}


void Widget::on_startButton_clicked()
{
    mPMap = new SudokuMap(":/mapA/Map/testMapA.txt",":/mapB/Map/testMapB.txt");
}

