#include "flyingchariot.h"
#include "game.h"

Shogi::flyingChariot::flyingChariot()
{

}

bool Shogi::flyingChariot::posibleMove(pion *pionToReplace, int SHIFT)
{
    if(((getPointer()->originalPos.y()!=pionToReplace->y())&&getPointer()->originalPos.x()==pionToReplace->x())||((getPointer()->originalPos.x()!=pionToReplace->x())&&getPointer()->originalPos.y()==pionToReplace->y()))
    {
        if(pionToReplace->getOwner()!=this->getOwner())
        {
            return true;
        }
    }
    return false;
}

Shogi::flyingChariot::~flyingChariot()
{

}

