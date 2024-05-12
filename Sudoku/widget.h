#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QMessageBox>
#include <QRandomGenerator>


#include <sudokumap.h>
#include <gamewidget.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    SudokuMap *mPMap;

private slots:
    void on_startButton_clicked();

    void reshow();

    void startGame(QString filenameA,QString filenameB);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
