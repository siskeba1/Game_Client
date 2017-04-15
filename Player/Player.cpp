#include "Player/Player.h"

QPoint Player::position() const
{
    return position_;
}

void Player::setPosition(const QPoint &position)
{
    position_ = position;
}

QRect Player::rectangle() const
{
    return rectangle_;
}

void Player::setRectangle(const QRect &rectangle)
{
    rectangle_ = rectangle;
}

Player::Player()
{
}
