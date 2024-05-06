#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QMessageBox>


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
    void on_loadButton_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H