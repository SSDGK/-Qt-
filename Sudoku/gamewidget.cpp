#include "gamewidget.h"
#include "ui_gamewidget.h"

GameWidget::GameWidget(SudokuMap *mPMap,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameWidget)
{
    ui->setupUi(this);
    makeMap(mPMap);
    for (int i = 0; i < 9; ++i)
    {
        QLayoutItem *Line = ui->mapLayout->itemAt(i);
        QHBoxLayout *LineLayout = (QHBoxLayout*)Line;
        if(Line)
        {
            for (int j = 0; j < 9; ++j)
            {
                QToolButton *Button = qobject_cast<QToolButton*>(LineLayout->itemAt(j)->widget());
                connect(Button,&QToolButton::clicked,this,&GameWidget::clickedChange);
            }

        }

    }

}

GameWidget::~GameWidget()
{
    delete ui;
}

void GameWidget::endGame()
{
    QMessageBox::warning(this,"GameOver","You Win!");
    emit gameEnd();
    this->close();
}
void GameWidget::clickedChange()
{

        QToolButton *clickedButton = qobject_cast<QToolButton*>(sender());
        if(clickedButton&&clickedButton->property("Hide").toBool())
        {
            if (clickedButton->property("selected").toBool()) {
                clickedButton->setIcon(QIcon(":/icon/icon/Unselected.png"));
                clickedButton->setProperty("selected", false);
            }
            else {
                clickedButton->setIcon(QIcon(":/icon/icon/Selected.png"));
                clickedButton->setProperty("selected", true);
            }
        }

}



void GameWidget::makeMap(SudokuMap *mPMap)
{
    for (int i = 0; i < 9; ++i)
    {
        QLayoutItem *Line = ui->mapLayout->itemAt(i);
        QHBoxLayout *LineLayout = (QHBoxLayout*)Line;
        if(Line)
        {
            for (int j = 0; j < 9; ++j)
            {
                QToolButton *Button = qobject_cast<QToolButton*>(LineLayout->itemAt(j)->widget());
                if(mPMap->NodeMap[i][j].hide)
                {
                    Button->setIcon(QIcon(":/icon/icon/Unselected.png"));
                    Button->setProperty("Hide",true);
                    Button->setProperty("LX",'A'+i);
                    Button->setProperty("LXX",j);
                    Button->setProperty("NUM",mPMap->NodeMap[i][j].num);
                }
                else
                {
                    QString iconPath = QString(":/icon/icon/icon%1.png").arg(mPMap->NodeMap[i][j].num);
                    Button->setIcon(QIcon(iconPath));
                    Button->setProperty("LX",'A'+i);
                    Button->setProperty("LXX",j);
                }

            }

        }

    }

};

void GameWidget::on_inpButton_1_clicked()
{
    bool key = true;
    for (int i = 0; i < 9; ++i)
    {
        QLayoutItem *Line = ui->mapLayout->itemAt(i);
        QHBoxLayout *LineLayout = (QHBoxLayout*)Line;
        if(Line)
        {
            for (int j = 0; j < 9; ++j)
            {
                QToolButton *Button = qobject_cast<QToolButton*>(LineLayout->itemAt(j)->widget());
                if(Button->property("Hide").toBool()&&Button->property("selected").toBool())
                {
                    if(Button->property("NUM")==1)
                    {
                        Button->setIcon(QIcon(":/icon/icon/icon1.png"));
                        Button->setProperty("Hide",false);
                    }
                }
                if(Button->property("Hide").toBool())
                {
                    key = false;
                }
            }

        }
    }
    if(key)
    {
        endGame();
    }
}


void GameWidget::on_inpButton_2_clicked()
{
    bool key = true;
    for (int i = 0; i < 9; ++i)
    {
        QLayoutItem *Line = ui->mapLayout->itemAt(i);
        QHBoxLayout *LineLayout = (QHBoxLayout*)Line;
        if(Line)
        {
            for (int j = 0; j < 9; ++j)
            {
                QToolButton *Button = qobject_cast<QToolButton*>(LineLayout->itemAt(j)->widget());
                if(Button->property("Hide").toBool()&&Button->property("selected").toBool())
                {
                    if(Button->property("NUM")==2)
                    {
                        Button->setIcon(QIcon(":/icon/icon/icon2.png"));
                        Button->setProperty("Hide",false);
                    }
                }
                if(Button->property("Hide").toBool())
                {
                    key = false;
                }
            }

        }
    }
    if(key)
    {
        endGame();
    }
}


void GameWidget::on_inpButton_3_clicked()
{
    bool key = true;
    for (int i = 0; i < 9; ++i)
    {
        QLayoutItem *Line = ui->mapLayout->itemAt(i);
        QHBoxLayout *LineLayout = (QHBoxLayout*)Line;
        if(Line)
        {
            for (int j = 0; j < 9; ++j)
            {
                QToolButton *Button = qobject_cast<QToolButton*>(LineLayout->itemAt(j)->widget());
                if(Button->property("Hide").toBool()&&Button->property("selected").toBool())
                {
                    if(Button->property("NUM")==3)
                    {
                        Button->setIcon(QIcon(":/icon/icon/icon3.png"));
                        Button->setProperty("Hide",false);
                    }
                }
                if(Button->property("Hide").toBool())
                {
                    key = false;
                }
            }

        }
    }
    if(key)
    {
        endGame();
    }
}


void GameWidget::on_inpButton_4_clicked()
{
    bool key = true;
    for (int i = 0; i < 9; ++i)
    {
        QLayoutItem *Line = ui->mapLayout->itemAt(i);
        QHBoxLayout *LineLayout = (QHBoxLayout*)Line;
        if(Line)
        {
            for (int j = 0; j < 9; ++j)
            {
                QToolButton *Button = qobject_cast<QToolButton*>(LineLayout->itemAt(j)->widget());
                if(Button->property("Hide").toBool()&&Button->property("selected").toBool())
                {
                    if(Button->property("NUM")==4)
                    {
                        Button->setIcon(QIcon(":/icon/icon/icon4.png"));
                        Button->setProperty("Hide",false);
                    }
                }
                if(Button->property("Hide").toBool())
                {
                    key = false;
                }
            }

        }
    }
    if(key)
    {
        endGame();
    }
}


void GameWidget::on_inpButton_5_clicked()
{
    bool key = true;
    for (int i = 0; i < 9; ++i)
    {
        QLayoutItem *Line = ui->mapLayout->itemAt(i);
        QHBoxLayout *LineLayout = (QHBoxLayout*)Line;
        if(Line)
        {
            for (int j = 0; j < 9; ++j)
            {
                QToolButton *Button = qobject_cast<QToolButton*>(LineLayout->itemAt(j)->widget());
                if(Button->property("Hide").toBool()&&Button->property("selected").toBool())
                {
                    if(Button->property("NUM")==5)
                    {
                        Button->setIcon(QIcon(":/icon/icon/icon5.png"));
                        Button->setProperty("Hide",false);
                    }
                }
                if(Button->property("Hide").toBool())
                {
                    key = false;
                }
            }

        }
    }
    if(key)
    {
        endGame();
    }
}


void GameWidget::on_inpButton_6_clicked()
{
    bool key = true;
    for (int i = 0; i < 9; ++i)
    {
        QLayoutItem *Line = ui->mapLayout->itemAt(i);
        QHBoxLayout *LineLayout = (QHBoxLayout*)Line;
        if(Line)
        {
            for (int j = 0; j < 9; ++j)
            {
                QToolButton *Button = qobject_cast<QToolButton*>(LineLayout->itemAt(j)->widget());
                if(Button->property("Hide").toBool()&&Button->property("selected").toBool())
                {
                    if(Button->property("NUM")==6)
                    {
                        Button->setIcon(QIcon(":/icon/icon/icon6.png"));
                        Button->setProperty("Hide",false);
                    }
                }
                if(Button->property("Hide").toBool())
                {
                    key = false;
                }
            }

        }
    }
    if(key)
    {
        endGame();
    }
}


void GameWidget::on_inpButton_7_clicked()
{
    bool key = true;
    for (int i = 0; i < 9; ++i)
    {
        QLayoutItem *Line = ui->mapLayout->itemAt(i);
        QHBoxLayout *LineLayout = (QHBoxLayout*)Line;
        if(Line)
        {
            for (int j = 0; j < 9; ++j)
            {
                QToolButton *Button = qobject_cast<QToolButton*>(LineLayout->itemAt(j)->widget());
                if(Button->property("Hide").toBool()&&Button->property("selected").toBool())
                {
                    if(Button->property("NUM")==7)
                    {
                        Button->setIcon(QIcon(":/icon/icon/icon7.png"));
                        Button->setProperty("Hide",false);
                    }
                }
                if(Button->property("Hide").toBool())
                {
                    key = false;
                }
            }

        }
    }
    if(key)
    {
        endGame();
    }
}


void GameWidget::on_inpButton_8_clicked()
{
    bool key = true;
    for (int i = 0; i < 9; ++i)
    {
        QLayoutItem *Line = ui->mapLayout->itemAt(i);
        QHBoxLayout *LineLayout = (QHBoxLayout*)Line;
        if(Line)
        {
            for (int j = 0; j < 9; ++j)
            {
                QToolButton *Button = qobject_cast<QToolButton*>(LineLayout->itemAt(j)->widget());
                if(Button->property("Hide").toBool()&&Button->property("selected").toBool())
                {
                    if(Button->property("NUM")==8)
                    {
                        Button->setIcon(QIcon(":/icon/icon/icon8.png"));
                        Button->setProperty("Hide",false);
                    }
                }
                if(Button->property("Hide").toBool())
                {
                    key = false;
                }
            }

        }
    }
    if(key)
    {
        endGame();
    }
}


void GameWidget::on_inpButton_9_clicked()
{
    bool key = true;
    for (int i = 0; i < 9; ++i)
    {
        QLayoutItem *Line = ui->mapLayout->itemAt(i);
        QHBoxLayout *LineLayout = (QHBoxLayout*)Line;
        if(Line)
        {
            for (int j = 0; j < 9; ++j)
            {
                QToolButton *Button = qobject_cast<QToolButton*>(LineLayout->itemAt(j)->widget());
                if(Button->property("Hide").toBool()&&Button->property("selected").toBool())
                {
                    if(Button->property("NUM")==9)
                    {
                        Button->setIcon(QIcon(":/icon/icon/icon9.png"));
                        Button->setProperty("Hide",false);
                    }
                }
                if(Button->property("Hide").toBool())
                {
                    key = false;
                }
            }

        }
    }
    if(key)
    {
        endGame();
    }
}

