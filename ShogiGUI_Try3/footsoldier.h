#ifndef FOOTSOLDIER_H
#define FOOTSOLDIER_H

#include "pion.h"

namespace Shogi
{
class FootSoldier: public pion
{
public:
    FootSoldier();
    bool posibleMove(pion* pionToReplace, int SHIFT);
    void rePos(){Text->setPos(getXText(),getYText());}
    ~FootSoldier();
};
}

#endif // FOOTSOLDIER_H
