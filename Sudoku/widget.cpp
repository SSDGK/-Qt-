#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_loadButton_clicked()
{
    mPMap = new SudokuMap(this);
    QString filenameA = QFileDialog::getOpenFileName(this,"选择地图文件A","F:\\QtProject\\Sudoku\\Map");
    QString filenameB = QFileDialog::getOpenFileName(this,"选择地图文件B","F:\\QtProject\\Sudoku\\Map");
    bool key = mPMap->readMap(filenameA,filenameB);
    if(key)
    {
        this->hide();
        GameWidget *gw = new GameWidget;
        gw->show();
    }
    else
    {
        QMessageBox::warning(this,"读取出现问题","请重新读取");
    }
}

