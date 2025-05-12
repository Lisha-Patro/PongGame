#include "Ball.h"

Ball::Ball(float startX, float startY)
{
    m_position.x = startX;
    m_position.y = startY;
    m_shape.setRadius(15);
    m_shape.setPosition(m_position);
    m_shape.setFillColor(Color::Red);
}
FloatRect Ball::getPosition()
{
    return m_shape.getGlobalBounds();
}
CircleShape Ball::getShape()
{
    return m_shape;
}
void Ball::reboundSides()
{
    m_directionX = -m_directionX;
}
void Ball::reboundTop()
{
    m_directionY = -m_directionY;
}
void Ball::reboundBat()
{
    m_directionX = -m_directionX;
}
void Ball::reboundBottom()
{
    m_directionY = -m_directionY;
}
void Ball::update(Time dt)
{
    m_position.x += m_directionX * m_speed * dt.asSeconds();
    m_position.y += m_directionY * m_speed * dt.asSeconds();
    m_shape.setPosition(m_position);
}
