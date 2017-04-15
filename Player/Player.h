#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QPoint>
#include <QRect>
#include <QGraphicsItem>

class Player : public QGraphicsItem
{
private:
    QPoint position_;
    QRect rectangle_;
public:
    Player();

    QPoint position() const;
    void setPosition(const QPoint &position);

    QRect rectangle() const;
    void setRectangle(const QRect &rectangle);
};

#endif // PLAYER_H
