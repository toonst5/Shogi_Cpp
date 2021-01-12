#include "footsoldier.h"
#include "game.h"


Shogi::FootSoldier::FootSoldier()
{

}

bool Shogi::FootSoldier::posibleMove(pion *pionToReplace, int SHIFT)
{

    if(this->getOwner()==QString("PLAYER1"))
    {
        if(getPointer()->originalPos.y()==(pionToReplace->y()+1*SHIFT)&&getPointer()->originalPos.x()==pionToReplace->x())
        {
            return true;
        }
    }else if(this->getOwner()==QString("PLAYER2"))
    {
        if(getPointer()->originalPos.y()==(pionToReplace->y()-1*SHIFT)&&getPointer()->originalPos.x()==pionToReplace->x())
        {
            return true;
        }
    }
    return false;
}

Shogi::FootSoldier::~FootSoldier()
{

}

