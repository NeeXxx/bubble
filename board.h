#ifndef BOARD_H
#define BOARD_H

#include "myMap.h"
#include "player.h"
#include "block.h"
#include <QtWidgets>
#include <QBasicTimer>
#include <QFrame>
#include <QPointer>


class board:public QFrame
{
public:
    board();
    bool tryMoveUp(player&);
    bool tryMoveDown(player&);
    bool tryMoveLeft(player&);
    bool tryMoveRight(player&);

private:
    player p1,p2;
    myMap m;

    bool trySimpleMove(int x1,int y1,int x2,int y2);
    bool tryPush(int x1,int y1,int x2,int y2);
    bool tryInToHide(int x1,int y1,int x2,int y2);

    bool tryMove(int x1,int y1,int x2,int y2);

    void explode();
    void setBomb();
    
    void countMapForDraw();
    substance mapForDraw[10][10];

protected:
    void paintEvent(QPaintEvent* event) Q_DECL_OVERRIDE;
    void keyPressEvent(QKeyEvent* event) Q_DECL_OVERRIDE;
};

#endif // BORAD_H
