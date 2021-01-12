#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

namespace Shogi
{
class Button:public QObject, public QGraphicsRectItem
{
    Q_OBJECT
private:
    QGraphicsTextItem* text;

public:
    Button();
    Button(QString name, QGraphicsItem* parent=NULL);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

signals:
    void clicked();
};
}

#endif // BUTTON_H
