#include "game_app.hpp"

GameApp::GameApp() : window(), board() { window.SetListener(this); }

void GameApp::Start() const { window.Show(); }

void GameApp::OnWindowRender() const { board.Render(); }

void GameApp::OnPlayer1Move(Move m) { board.MovePlayer1(m == Move::UP); }