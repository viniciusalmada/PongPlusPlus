#pragma once

#include "game_window.hpp"
#include "board.hpp"

class GameApp : private GameWindowListener
{
public:
  GameApp();

  void Start() const;

private:
  void OnWindowRender() const override;

  GameWindow window;
  
  Board board;
};