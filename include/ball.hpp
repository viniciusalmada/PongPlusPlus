#pragma once

#include <GraRen/circle.hpp>
#include <GraRen/point.hpp>

class Ball
{
public:
  Ball(GraRen::Point position);

  GraRen::Circle GetDrawable() const;

private:
  GraRen::Point position;
};