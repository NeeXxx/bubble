#include "board.h"
#include <QPainter>
#include <QImage>
#include <QPixmap>

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
    QPainter painter(this);
    painter.translate(20,100);
    QPixmap ground;
    ground.load("../Bubbles/images/ground.png");
    painter.drawPixmap(0,0,900,900,ground);
    countMapForDraw();
    for (int i=1;i<10;i++)
    {
        for (int j=1;j<10;j++)
        {
            substance judge=mapForDraw[i][j];
            texture image;
            if (judge.us==tree&&judge.us==water&&judge.us==house)
            {
                underSubstance tmp=judge.us;
                switch(tmp)
                {
                case tree:
                {
                    image=t_tree;
                    break;
                }
                case water:
                {
                    image=t_nothing;
                    break;
                }
                case house:
                    image=t_house;
                    break;
                }
            }
            else
            {
                aboveSubstance tmp=judge.as;
                switch(tmp)
                {
                case bomb:
                {
                    image=t_bomb;
                }
                case arrowDown:
                case arrowLeft:
                case arrowRight:
                case arrowUp:
                {
                    image=t_flame;
                }
                case player1:
                {
                    image=t_player1;
                }
                case player2:
                {
                    image=t_player2;
                }
                case wood:
                {
                    image=t_wood;
                }
                case air:
                {
                    image=t_nothing;
                }
                }
            }
            switch(image)
            {
            case t_nothing:
            {
                break;
            }
            case t_player1:
            {
                QPixmap pix;
                pix.load("../Bubbles/images/player1.png");
                painter.drawPixmap(100*i-100,100*j-120,100,120,pix);
                break;
            }
            case t_player2:
            {
                QPixmap pix;
                pix.load("../Bubbles/images/player2.png");
                painter.drawPixmap(100*i-100,100*j-120,100,120,pix);
                break;
            }
            case t_tree:
            {
                QPixmap pix;
                pix.load("../Bubbles/images/tree.png");
                painter.drawPixmap(100*i-100,100*j-120,100,120,pix);
                break;
            }
            case t_wood:
            {
                QPixmap pix;
                pix.load("../Bubbles/images/wood.png");
                painter.drawPixmap(100*i-100,100*j-120,100,120,pix);
                break;
            }
            case t_bomb:
            {
                QPixmap pix;
                pix.load("../Bubbles/images/bomb.png");
                painter.drawPixmap(100*i-100,100*j-120,100,120,pix);
                break;
            }
            case t_house:
            {
                QPixmap pix;
                pix.load("../Bubbles/images/house.png");
                painter.drawPixmap(100*i-100,100*j-120,100,120,pix);
                break;
            }
            case t_flame:
            {
                QPixmap pix;
                pix.load("../Bubbles/images/flame.png");
                painter.drawPixmap(100*i-100,100*j-120,100,120,pix);
                break;
            }
            }
        }
    }
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
