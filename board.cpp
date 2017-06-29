#include "board.h"

board::board():p1(),p2()
{

}

bool board::tryMove(int x1,int y1,int x2,int y2) //from 1 to 2
{
    block& target=m.blockAt(x2,y2);
    if(target.inable())
    {
        if(target.hidable())
            return tryInToHide(x1,y1,x2,y2);
        else
            return trySimpleMove(x1,y1,x2,y2);
    }
    else
    {
        if(target.pushable())
            return tryPush(x1,y1,x2,y2);
        else return false;
    }
}
//bug?

bool board::trySimpleMove(int x1,int y1,int x2,int y2)
{
    m.moveAToB(x1,y1,x2,y2);
    return true;
}

bool board::tryPush(int x1,int y1,int x2,int y2)
{
    block& target1=m.blockAt(x2,y2);
    int x3=x2+x2-x1,y3=y2+y2-y1;
    block& target2=m.blockAt(x3,y3);

    if(target2.inable())
    {
        if(target1.hidable())
            return tryInToHide(x1,y1,x2,y2);
        else
            return trySimpleMove(x1,y1,x2,y2);

        if(target2.hidable())
            return tryInToHide(x2,y2,x3,y3);
        else
            return trySimpleMove(x2,y2,x3,y3);
    }
    else
        return false;
}

bool board::tryInToHide(int x1,int y1,int x2,int y2)
{
    m.moveAToB(x1,y1,x2,y2);
    return true;
}

void board::countMapForDraw()
{
    for(int i=1;i<=10;i++)
        for(int j=1;j<=10;j++)
        {
            mapForDraw[i][j]=m.blockAt(i,j).appearance();
        }
}

void board::paintEvent(QPaintEvent* event)
{
    countMapForDraw();
}

void board::keyPressEvent(QKeyEvent* event)
{
    switch(event->key())
    {
    //p1:
    case Qt::Key_W:
        tryMoveUp(p1);
        break;
    case Qt::Key_S:
        tryMoveDown(p1);
        break;
    case Qt::Key_A:
        tryMoveLeft(p1);
        break;
    case Qt::Key_D:
        tryMoveRight(p1);
        break;

    //p2:
    case Qt::Key_Up:
        tryMoveUp(p2);
        break;
    case Qt::Key_Down:
        tryMoveDown(p2);
        break;
    case Qt::Key_Left:
        tryMoveLeft(p2);
        break;
    case Qt::Key_Right:
        tryMoveRight(p2);
        break;
    }
}
