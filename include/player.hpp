#pragma once

#include <GraRen/rectangle.hpp>

class Player
{
public:
  enum class Side { LEFT, RIGHT };

  Player(int size, int position, Side side);

  GraRen::Rectangle GetDrawable() const;

  int GetPosition() const { return position; };

  void IncrementPosition();

  void DecrementPosition();

private:
  int size;
  int position;
  Side side;
};