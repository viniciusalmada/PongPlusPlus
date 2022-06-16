#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

class GameWindowListener
{
public:
  enum class Move { UP, DOWN };

  virtual void OnWindowRender() const = 0;

  virtual void OnPlayer1Move(Move m) = 0;
};

class GameWindow
{
public:
  GameWindow();

  void Show() const;

  void SetListener(GameWindowListener* listener);

private:
  static constexpr int WIDTH = 640;
  static constexpr int HEIGHT = 480;
  static const std::string TITLE;

  static void OnKeyEventListener(GLFWwindow* window,
                                 int key,
                                 int scanCode,
                                 int action,
                                 int mods);

  GLFWwindow* InitWindow() const;

  void InitGLEW() const;

  GLFWwindow* window;

  GameWindowListener* listener;
};