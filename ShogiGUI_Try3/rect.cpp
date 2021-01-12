#include "rect.h"

Shogi::rect::rect()
{
    QRect rect(0,0,10,10);

    QVector<QPointF> pentPoints;
    pentPoints << QPointF(0,10) << QPointF(10,10) << QPointF(10,0) << QPointF(0,0) << QPointF(0,10);

    int Scale_By = 11;
    for (size_t i = 0, n = pentPoints.size(); i<n; i++)
    {
        pentPoints[i] *= Scale_By;
    }

    QPolygonF pent(pentPoints);
    setPolygon(pent);
}
