// Copyright 2019 Yanshi
//#####################################################################
// Class ImGui_Wrapper
//######################################################################
#ifndef IMGUI_WRAPPER_H_
#define IMGUI_WRAPPER_H_

#include "FluidSolver.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

namespace opengl_gui_viewer
{

class ImGui_Wrapper
{
public:
  ImGui_Wrapper();
  ~ImGui_Wrapper();

  void Initialize(GLFWwindow *window);
  void Render();

  FluidSolver *fluid_solver;
  GLFWwindow *_window;
  

  


  GLuint VBO, VAO, EBO;




  // ============ Considering Manage Render Object in another file ========

  void UIFrame();
  void DisplayUI();

  void test_GenObject();
  void InitBuffer();
  void NewBuffer();
  // Listen for every frame
  void ApplyDisplayOption();

  // ============ Considering Manage Render Object in another file ========

  // ImGui IO
  void MouseWheelScrollCallback(float yoffset);
  void MouseButtonCallback(const int button, const int action);
  void KeyboardCallback(const int key, const int action);
  float GetIOFramerate();
  glm::vec2 GetMouseDelta();
  glm::vec2 GetMousePosition();

private:
  // Mouse states.
  bool _mouse_pressed_[3];
  float _mouse_wheel_;

  // ============ Considering Manage Render Object in another file ========
  // Cube Paras
  double tmpParas_cube[3];

  void DisplayCubeModule();
  void DisplayHoleModule();
  void DisplayOptionModule();
  void DisplayGenerateModule();
  void DisplayAnimation();
  // ============ Considering Manage Render Object in another file ========
};

} // namespace opengl_gui_viewer

#endif // IMGUI_WRAPPER_H_
