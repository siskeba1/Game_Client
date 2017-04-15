#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include <QGraphicsScene>

class Scene : public QGraphicsScene
{
public:
    Scene(QObject* parent);
protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif // SCENE_H
