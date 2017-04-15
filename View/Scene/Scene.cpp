#include "Scene.h"
#include <QGraphicsSceneMouseEvent>
#include <QPointF>
#include <QDebug>

Scene::Scene(QObject *parent) : QGraphicsScene(parent)
{

}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QLine line;
    line.setP1(QPoint(0, 0));
    line.setP2(event->scenePos().toPoint());

    QPen pen;
    pen.setColor(QColor(0, 0, 0));
    addLine(line, pen);
    qDebug() << event->scenePos();
    qDebug() << event->pos();
    qDebug() << "scene: asd asd asd " << event->pos().toPoint();
}
