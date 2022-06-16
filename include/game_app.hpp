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
  
  void OnPlayer1Move(Move m) override;

  GameWindow window;
  
  Board board;
};