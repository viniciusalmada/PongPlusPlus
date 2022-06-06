#pragma once

#include "drawable.hpp"

class Player : public IDrawable
{
public:
  enum class Side { LEFT, RIGHT };

  Player(int size, int position, Side side);

  GraRen::IElement GetDrawable() const override;

private:
  int size;
  int position;
  Side side;
};