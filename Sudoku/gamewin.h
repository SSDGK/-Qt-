#ifndef GAMEWIN_H
#define GAMEWIN_H

#include <QWidget>
#include <QRandomGenerator>

namespace Ui {
class GameWin;
}

class GameWin : public QWidget
{
    Q_OBJECT

public:
    explicit GameWin(QWidget *parent = nullptr);
    ~GameWin();

private:
    Ui::GameWin *ui;
};

#endif // GAMEWIN_H
