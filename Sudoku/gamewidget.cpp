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
    for (int i = 0; i < 9; ++i)
    {
        QLayoutItem *Line = ui->mapLayout->itemAt(i);
        QHBoxLayout *LineLayout = qobject_cast<QHBoxLayout*>(Line->widget());
        if(Line)
        {
            for (int j = 0; j < 9; ++j)
            {
                QLayoutItem *item = LineLayout->itemAt(j);
                QToolButton *Button = qobject_cast<QToolButton*>(item->widget());
                if(mPMap->NodeMap[i][j].hide)
                {
                    Button->setIcon(QIcon(":/icon/icon/Unselected.png"));
                }
                else
                {
                    QString iconPath = QString(":/icon/icon/icon%1.png").arg(mPMap->NodeMap[i][j].num);
                    Button->setIcon(QIcon(iconPath));
                }

            }

        }

    }

};
