#include "pion.h"
#include <QPointF>
#include <QPolygonF>
#include <QVector>
#include <QBrush>
#include "game.h"

Shogi::pion::pion(QGraphicsItem* parent)
{
    QVector<QPointF> pentPoints;
    pentPoints << QPointF(0,10) << QPointF(1,2) << QPointF(4,0) << QPointF(7,2) << QPointF(8,10);

    int Scale_By = 8;
    for (size_t i = 0, n = pentPoints.size(); i<n; i++)
    {
        pentPoints[i] *= Scale_By;
    }

    QPolygonF pent(pentPoints);
    setPolygon(pent);
    yard=false;
}


void Shogi::pion::setOwner(QString player)
{
    owner = player;

    if(player == QString("NOONE"))
    {
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(QColor(0,0,0,50));
        setBrush(brush);

        QVector<QPointF> pentPoints;
        pentPoints << QPointF(0,0) << QPointF(0,10) << QPointF(10,10) << QPointF(10,0) << QPointF(0,0);

        int Scale_By = 8;
        for (size_t i = 0, n = pentPoints.size(); i<n; i++)
        {
            pentPoints[i] *= Scale_By;
        }

        QPolygonF pent(pentPoints);
        setPolygon(pent);
    }else if(player == QString("PLAYER1"))
    {
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(QColor(205,170,109,255));
        setBrush(brush);

        QVector<QPointF> pentPoints;
        pentPoints << QPointF(0,10) << QPointF(1,2) << QPointF(4,0) << QPointF(7,2) << QPointF(8,10);

        int Scale_By = 8;
        for (size_t i = 0, n = pentPoints.size(); i<n; i++)
        {
            pentPoints[i] *= Scale_By;
        }

        QPolygonF pent(pentPoints);
        setPolygon(pent);
    }else if(player == QString("PLAYER2"))
    {
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(QColor(242,169,0,255));
        setBrush(brush);

        QVector<QPointF> pentPoints;
        pentPoints << QPointF(0,1) << QPointF(1,8) << QPointF(4,10) << QPointF(7,8) << QPointF(8,1);

        int Scale_By = 8;
        for (size_t i = 0, n = pentPoints.size(); i<n; i++)
        {
            pentPoints[i] *= Scale_By;
        }

        QPolygonF pent(pentPoints);
        setPolygon(pent);
    }else if(player == QString("GRAVE"))
    {
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(QColor(100,100,100,100));
        setBrush(brush);

        QVector<QPointF> pentPoints;
        pentPoints << QPointF(0,0) << QPointF(0,10) << QPointF(10,10) << QPointF(10,0) << QPointF(0,0);

        int Scale_By = 7;
        for (size_t i = 0, n = pentPoints.size(); i<n; i++)
        {
            pentPoints[i] *= Scale_By;
        }

        QPolygonF pent(pentPoints);
        setPolygon(pent);
    }
}

void Shogi::pion::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(P->cardToPlace == nullptr)
    {
        P->pickUpCard(this);
    }else
    {
        if(P->cardToPlace->getYard())
        {
            if((P->cardToPlace->getOwner()==QString("PLAYER2"))&&this->y()>3&&this->getOwner()==QString("NOONE"))
            {
                P->placeCard(this);
            }else if((P->cardToPlace->getOwner()==QString("PLAYER1"))&&this->y()>3&&this->getOwner()==QString("NOONE"))
            {
                P->placeCard(this);
            }
        }else if(P->cardToPlace->posibleMove(this,110))
        {
            P->placeCard(this);
        }
    }
}

void Shogi::pion::draw(QString jap)
{
    QGraphicsTextItem* text= new QGraphicsTextItem(jap);
    Text=text;
    X=this->x()+25;
    Y=this->y()+30;
    text->setPos(X,Y);
    P->scene->addItem(this);
    P->scene->addItem(text);
}
