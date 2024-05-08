#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <sudokumap.h>

namespace Ui {
class GameWidget;
}

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameWidget(SudokuMap *mPMap,QWidget *parent = nullptr);
    //virtual void paintEvent(QPaintEvent* event);
    ~GameWidget();

    void makeMap(SudokuMap *mPMap);

private slots:
    void on_pushButton_clicked();

private:
    Ui::GameWidget *ui;
    //QPainter* mMapPainter;
};


#endif // GAMEWIDGET_H
