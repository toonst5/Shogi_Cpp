#ifndef BOARD_H
#define BOARD_H

#include <QList>
#include "pion.h"
#include "rect.h"
#include "space.h"
#include "kinggeneral.h"
#include "footsoldier.h"
#include "flyingchariot.h"

namespace Shogi
{
class game;
class board
{
private:
    void creatPionColm(int x, int y, int numPionen, QString player, QString soort);
    QList<pion*> Pionen;
    game* P;
    const unsigned char SHIFT=110;

public:
    board();

    board(game* W);

    QList<pion*> getPionen();

    void placePionen(int x, int y/*, int cols, int rows*/);
};
}

#endif // BOARD_H
