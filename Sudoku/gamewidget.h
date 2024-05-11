#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <sudokumap.h>
#include <QMessageBox>

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
    void endGame();

private slots:
    void clickedChange();

    void on_inpButton_1_clicked();

    void on_inpButton_2_clicked();

    void on_inpButton_3_clicked();

    void on_inpButton_4_clicked();

    void on_inpButton_5_clicked();

    void on_inpButton_6_clicked();

    void on_inpButton_7_clicked();

    void on_inpButton_8_clicked();

    void on_inpButton_9_clicked();

private:
    Ui::GameWidget *ui;
    //QPainter* mMapPainter;
};


#endif // GAMEWIDGET_H
