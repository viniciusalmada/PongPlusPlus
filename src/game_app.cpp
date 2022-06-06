#include "game_app.hpp"

GameApp::GameApp() : window(), board()
{
  window.SetListener(this);
  window.Show();
};

void GameApp::OnWindowRender() const { board.Render(); };