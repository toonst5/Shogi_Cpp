#ifndef KINGGENERAL_H
#define KINGGENERAL_H

#include "pion.h"

namespace Shogi
{
class kingGeneral: public pion
{
public:
    kingGeneral();
    bool posibleMove(pion* pionToReplace, int SHIFT);
    void rePos(){Text->setPos(getXText(),getYText());}
    ~kingGeneral();
};
}

#endif // KINGGENERAL_H
