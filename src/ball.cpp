#include "ball.hpp"

Ball::Ball(GraRen::Point position) : position(position) {}

GraRen::IElement Ball::GetDrawable() const
{
  GraRen::Point bot_left = position - GraRen::Point{ 20 / 2, 20 / 2 };

  GraRen::Rectangle rect{ bot_left, 20, 20 };

  return static_cast<GraRen::IElement>(rect);
}