#pragma once

#include "idrawable.hpp"

class Player : public IDrawable
{
public:
  enum class Side { LEFT, RIGHT };

  Player(int size, int position, Side side);

  GraRen::Rectangle GetDrawable() const override;

private:
  int size;
  int position;
  Side side;
};