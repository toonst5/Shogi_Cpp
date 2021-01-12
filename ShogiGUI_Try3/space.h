#ifndef SPACE_H
#define SPACE_H


#include "pion.h"

namespace Shogi
{
class space: public pion
{
private:
    bool posible;
public:
    space():posible(true){};
    bool posibleMove(pion* pionToReplace, int SHIFT){return posible;}
    void rePos(){Text->setPos(getXText(),getYText());}
};
}

#endif // SPACE_H
