#pragma once

#include "ball.hpp"
#include "player.hpp"

class Board
{
public:
  Board();

private:
  static constexpr int WIDTH = 640;
  static constexpr int HEIGHT = 480;

  Ball ball;
  Player player1;
  Player player2;
};