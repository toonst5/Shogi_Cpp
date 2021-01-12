#include "kinggeneral.h"
#include "game.h"


Shogi::kingGeneral::kingGeneral()
{

}

bool Shogi::kingGeneral::posibleMove(pion *pionToReplace, int SHIFT)
{
    if((getPointer()->originalPos.y()==(pionToReplace->y()+1*SHIFT)||getPointer()->originalPos.y()==(pionToReplace->y()-1*SHIFT)||getPointer()->originalPos.x()==(pionToReplace->x()+1*SHIFT)||getPointer()->originalPos.x()==(pionToReplace->x()-1*SHIFT))&&(getPointer()->originalPos.y()>=(pionToReplace->y()+2*SHIFT))!=true&&(getPointer()->originalPos.y()<=(pionToReplace->y()-2*SHIFT))!=true&&(getPointer()->originalPos.x()>=(pionToReplace->x()+2*SHIFT))!=true&&(getPointer()->originalPos.x()<=(pionToReplace->x()-2*SHIFT))!=true)
    {
        return true;
    }
    return false;
}

Shogi::kingGeneral::~kingGeneral()
{

}

