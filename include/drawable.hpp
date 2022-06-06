#pragma once

#include <GraRen/rectangle.hpp>

class IDrawable
{
public:
  virtual GraRen::IElement GetDrawable() const = 0;
};