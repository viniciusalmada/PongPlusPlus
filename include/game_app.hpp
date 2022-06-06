#pragma once

#include "game_window.hpp"
#include "board.hpp"

class GameApp : private GameWindowListener
{
public:
  GameApp();

private:
  void OnWindowRender() const override;

  GameWindow window;
  
  Board board;
};