#include "player.hpp"

#include "board_const.hpp"

Player::Player(int size, int position, Side side)
    : size(size), position(position), side(side)
{
}

GraRen::Rectangle Player::GetDrawable() const
{
  GraRen::Number x_bot_left;
  if (side == Side::LEFT)
    x_bot_left = 0;
  else
    x_bot_left = BOARD_WIDTH - 20;

  GraRen::Number y_bot_left = position - size / 2;
  GraRen::Point bot_left{ x_bot_left, y_bot_left };

  return GraRen::Rectangle{ bot_left, 20, size };
};