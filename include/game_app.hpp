#pragma once

#include "game_window.hpp"
#include "board.hpp"

class GameApp
{
public:
  GameApp();

private:
  GameWindow window;
  
  Board board;
};