#include "ball.hpp"

Ball::Ball(GraRen::Point position) : position(position) {}

GraRen::Circle Ball::GetDrawable() const
{
  GraRen::Point center = position;

  return GraRen::Circle{ center, 15, GraRen::Color::RED };
}