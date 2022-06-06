#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

class GameWindowListener
{
public:
  virtual void OnWindowRender() const = 0;
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

  GLFWwindow* InitWindow() const;

  void InitGLEW() const;

  GLFWwindow* window;

  GameWindowListener* listener;
};