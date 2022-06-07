#pragma once

#include <GraRen/rectangle.hpp>

class Player
{
public:
  enum class Side { LEFT, RIGHT };

  Player(int size, int position, Side side);

  GraRen::Rectangle GetDrawable() const;

private:
  int size;
  int position;
  Side side;
};