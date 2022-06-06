#include "ball.hpp"

Ball::Ball(GraRen::Point position) : position(position) {}

GraRen::Rectangle Ball::GetDrawable() const
{
  GraRen::Point bot_left = position - GraRen::Point{ 20 / 2, 20 / 2 };

  return GraRen::Rectangle{ bot_left, 20, 20, GraRen::Color::RED };
}