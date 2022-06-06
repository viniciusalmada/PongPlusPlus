#pragma once

#include "drawable.hpp"

#include <GraRen/point.hpp>

class Ball : public IDrawable
{
public:
  Ball(GraRen::Point position);

  GraRen::IElement GetDrawable() const override;

private:
  GraRen::Point position;
};