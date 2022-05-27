#include "game_window.hpp"

#include <iostream>

const std::string GameWindow::TITLE = "Pong++";

GameWindow::GameWindow() : window(InitWindow()) { InitGLEW(); }

GLFWwindow* GameWindow::InitWindow() const
{
  if (glfwInit() == GLFW_FALSE)
  {
    throw std::runtime_error("GLFW did not initialize!");
  }

  GLFWwindow* win =
    glfwCreateWindow(WIDTH, HEIGHT, TITLE.c_str(), nullptr, nullptr);
  glfwSetWindowAttrib(win, GLFW_RESIZABLE, GLFW_FALSE);
  return win;
}

void GameWindow::InitGLEW() const
{
  if (window == nullptr)
    throw std::runtime_error("Window has not been initialized!");

  glfwMakeContextCurrent(window);

  if (glewInit() != GLEW_OK)
  {
    throw std::runtime_error("GLEW did not initialize!");
  }
}

void GameWindow::Show() const
{
  do
  {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glfwSwapBuffers(window);

    glfwPollEvents();
  } while (!glfwWindowShouldClose(window));
}