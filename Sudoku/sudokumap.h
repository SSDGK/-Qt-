#ifndef SUDOKUMAP_H
#define SUDOKUMAP_H

#include <QObject>
#include <QFileDialog>
#include <QFile>

class NumNode
{
public:
    int num;
    bool hide;
};

class SudokuMap : public QObject
{
    Q_OBJECT
public:
    explicit SudokuMap(QObject *parent = nullptr);
    ~SudokuMap();
    NumNode **NodeMap;

    bool readMap(QString filenameA,QString filenameB);
    void Clear();


signals:
};

#endif // SUDOKUMAP_H
