#pragma once

#include "idrawable.hpp"

#include <GraRen/point.hpp>

class Ball : public IDrawable
{
public:
  Ball(GraRen::Point position);

  GraRen::Rectangle GetDrawable() const override;

private:
  GraRen::Point position;
};