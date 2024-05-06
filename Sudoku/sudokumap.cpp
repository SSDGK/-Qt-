#include "sudokumap.h"

SudokuMap::SudokuMap(QObject *parent)
    : QObject{parent}
{
    NodeMap = nullptr;
}
SudokuMap::~SudokuMap()
{
    Clear();
}

void SudokuMap::Clear()
{
    for (int i = 0; i < 9; ++i)
    {
        delete NodeMap[i];
    }
    delete NodeMap;
}


bool SudokuMap::readMap(QString filenameA,QString filenameB)
{
    QFile mapFileA(filenameA);
    QFile mapFileB(filenameB);
    if(!mapFileA.open(QIODevice::ReadOnly)||!mapFileB.open(QIODevice::ReadOnly))
    {
        return false;
    }
    QByteArray arrAllA = mapFileA.readAll();
    QByteArray arrAllB = mapFileB.readAll();
    arrAllA.replace("\r\n","\n");
    arrAllB.replace("\r\n","\n");
    QList<QByteArray> lineListA = arrAllA.split('\n');
    QList<QByteArray> lineListB = arrAllB.split('\n');
    NodeMap = new NumNode*[9];

    for (int i = 0; i < 9; ++i)
    {
        QList<QByteArray> colListA = lineListA[i].split(',');
        QList<QByteArray> colListB = lineListB[i].split(',');
        NodeMap[i] = new NumNode[9];
        for (int j = 0; j < 9; ++j)
        {
            NodeMap[i][j].num = colListA[j].toInt();
            if(colListB[j].toInt()==0)NodeMap[i][j].hide = true;
            else NodeMap[i][j].hide = false;
        }
    }
    return true;
}
