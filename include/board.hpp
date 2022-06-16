#pragma once

#include "ball.hpp"
#include "player.hpp"

#include <GraRen/canvas.hpp>

class Board
{
public:
  Board();

  void Render() const;

  void MovePlayer1(bool toUp);
  
  void MovePlayer2(bool toUp);

private:
  void UpdateBoard();

  Ball ball;
  Player player1;
  Player player2;

  GraRen::Canvas canvas;
};