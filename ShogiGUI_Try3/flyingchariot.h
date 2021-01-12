#ifndef FLYINGCHARIOT_H
#define FLYINGCHARIOT_H

#include "pion.h"

namespace Shogi
{
class flyingChariot: public pion
{
public:
    flyingChariot();
    bool posibleMove(pion* pionToReplace, int SHIFT);
    void rePos(){Text->setPos(getXText(),getYText());}
    ~flyingChariot();
};
}

#endif // FLYINGCHARIOT_H
