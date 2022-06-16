#include "game_window.hpp"

#include <iostream>

const std::string GameWindow::TITLE = "Pong++";

GameWindow::GameWindow() : window(InitWindow()), listener(nullptr)
{
  InitGLEW();

  glfwSetWindowUserPointer(window, this);
}

GLFWwindow* GameWindow::InitWindow() const
{
  if (glfwInit() == GLFW_FALSE)
  {
    throw std::runtime_error("GLFW did not initialize!");
  }

  GLFWwindow* win =
    glfwCreateWindow(WIDTH, HEIGHT, TITLE.c_str(), nullptr, nullptr);

  glfwSetWindowAttrib(win, GLFW_RESIZABLE, GLFW_FALSE);

  glfwSetKeyCallback(win, OnKeyEventListener);
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

    if (listener != nullptr)
    {
      listener->OnWindowRender();
    }
    glfwSwapBuffers(window);

    glfwPollEvents();
  } while (!glfwWindowShouldClose(window));
}

void GameWindow::SetListener(GameWindowListener* new_listener)
{
  this->listener = new_listener;
}

void GameWindow::OnKeyEventListener(GLFWwindow* window,
                                    int key,
                                    int /* scanCode */,
                                    int action,
                                    int /* mods */)
{
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
  {
    glfwSetWindowShouldClose(window, GLFW_TRUE);
    return;
  }

  if (action == GLFW_PRESS || action == GLFW_REPEAT)
  {
    GameWindow* self = static_cast<GameWindow*>(glfwGetWindowUserPointer(window));
    if (key == GLFW_KEY_W){
      self->listener->OnPlayer1Move(GameWindowListener::Move::UP);
      return;
    }
    if (key == GLFW_KEY_S){
      self->listener->OnPlayer1Move(GameWindowListener::Move::DOWN);
      return;
    }
  }
}