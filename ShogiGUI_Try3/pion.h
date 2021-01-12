#ifndef PION_H
#define PION_H

#include <QGraphicsPolygonItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>


namespace Shogi
{
class game;
class pion: public QGraphicsPolygonItem
{
private:
    bool isPlaced;
    QString owner;
    bool yard;

    game* P;
    short X;
    short Y;

public:

    pion(QGraphicsItem* parent=NULL);

    void setPointer(game* W){this->P=W;}
    game* getPointer(){return this->P;}

    short getXText(){return X;}
    short getYText(){return Y;}
    void setXText(int x = 0){X=x;}
    void setYText(int y = 0){Y=y;}

    bool getIsPlaced(){return isPlaced;}
    QString getOwner(){return owner;}
    bool getYard(){return yard;}
    void setYard(bool Y){yard=Y;}

    void setOwner(QString);
    void setIsPlaced(bool b){isPlaced=b;}

    void mousePressEvent(QGraphicsSceneMouseEvent* event);

    virtual bool posibleMove(pion* pionToReplace, int shift)=0;
    void draw(QString jap);
    virtual void rePos()=0;

    QGraphicsTextItem* Text;
};
}

#endif // PION_H
