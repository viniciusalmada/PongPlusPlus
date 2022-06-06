#pragma once

#include "ball.hpp"
#include "player.hpp"

#include <GraRen/canvas.hpp>

class Board
{
public:
  Board();

  void Render() const;

private:
  Ball ball;
  Player player1;
  Player player2;

  GraRen::Canvas canvas;
};