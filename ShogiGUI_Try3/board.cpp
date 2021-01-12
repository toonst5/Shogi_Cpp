#include "board.h"
#include "game.h"

Shogi::board::board()
{

}

Shogi::board::board(game* W)
{
    this->P=W;
}


QList<Shogi::pion *> Shogi::board::getPionen()
{
    return Pionen;
}

void Shogi::board::placePionen(int x, int y/*, int cols, int rows*/)
{

    creatPionColm(x,y+3*SHIFT,9,QString("NOONE"),QString("NON"));
    creatPionColm(x,y+4*SHIFT,9,QString("NOONE"),QString("NON"));
    creatPionColm(x,y+5*SHIFT,9,QString("NOONE"),QString("NON"));
    creatPionColm(x,y+1*SHIFT,1,QString("NOONE"),QString("NON"));
    creatPionColm(x+2*SHIFT,y+1*SHIFT,5,QString("NOONE"),QString("NON"));
    creatPionColm(x+8*SHIFT,y+1*SHIFT,1,QString("NOONE"),QString("NON"));
    creatPionColm(x,y+7*SHIFT,1,QString("NOONE"),QString("NON"));
    creatPionColm(x+2*SHIFT,y+7*SHIFT,5,QString("NOONE"),QString("NON"));
    creatPionColm(x+8*SHIFT,y+7*SHIFT,1,QString("NOONE"),QString("NON"));

    creatPionColm(x,y,9,QString("PLAYER2"),QString("KING"));
    creatPionColm(x+1*SHIFT,y+1*SHIFT,1,QString("PLAYER2"),QString("ROOK"));
    creatPionColm(x+7*SHIFT,y+1*SHIFT,1,QString("PLAYER2"),QString("ROOK"));
    creatPionColm(x,y+2*SHIFT,9,QString("PLAYER2"),QString("PION"));

    creatPionColm(x,y+6*SHIFT,9,QString("PLAYER1"),QString("PION"));
    creatPionColm(x+1*SHIFT,y+7*SHIFT,1,QString("PLAYER1"),QString("ROOK"));
    creatPionColm(x+7*SHIFT,y+7*SHIFT,1,QString("PLAYER1"),QString("ROOK"));
    creatPionColm(x,y+8*SHIFT,9,QString("PLAYER1"),QString("KING"));
}

void Shogi::board::creatPionColm(int x, int y, int numPionen, QString player, QString soort)
{
    for(size_t i=0; i<numPionen; i++)
    {
        rect* Rect = new rect();
        Rect->setPos(x+110*i,y);
        P->scene->addItem(Rect);

        pion* Pion=nullptr;
        if(soort == QString("PION"))
        {
            Pion = new FootSoldier();
        }else if(soort == QString("KING"))
        {
            Pion = new kingGeneral();
        }else if(soort == QString("ROOK"))
        {
            Pion = new flyingChariot();
        }else
        {
            Pion = new space();
        }

        Pion->setPointer(P);
        Pion->setPos(x+110*i+17.5,y+15);
        Pionen.append(Pion);
        Pion->setIsPlaced(true);

        if(soort == QString("PION"))
        {
            Pion->draw(QString("歩\n兵"));
        }else if(soort == QString("KING"))
        {
            Pion->draw(QString("王\n將"));
        }else if(soort == QString("ROOK"))
        {
            Pion->draw(QString("飛\n車"));
        }else
        {
            Pion->draw(QString(""));
        }

        Pion->setOwner(player);
    }
}
