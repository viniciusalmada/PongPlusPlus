#pragma once

#include <GraRen/rectangle.hpp>

class IDrawable
{
public:
  virtual GraRen::Rectangle GetDrawable() const = 0;
};