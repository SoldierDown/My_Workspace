// @yanshi
//#####################################################################
// Class OGL_World
//######################################################################
#ifndef OGL_WORLD_
#define OGL_WORLD_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

// #include "Camera.h"
#include "Viewer.h"

namespace opengl_gui_viewer
{

class World
{
  private:
    GLFWwindow *window;
    Viewer *viewer;
    int window_width, window_height;
    glm::vec2 mouse_position = glm::vec2(0,0);
    // Initialize
    void Initialize_Viewer();
    // void Initialize_Camera_Controls();

  public:
    World(int size_x, int size_y);
    ~World();
    
    void Initialize();
    void Main_Loop();

    // === Callback ===
    static void Close_Callback(GLFWwindow *window);
    static void Scroll_Callback(GLFWwindow *window, double xoffset, double yoffset);
    static void Reshape_Callback(GLFWwindow *window, int w, int h);
    static void Keyboard_Callback(GLFWwindow *window, int key, int scancode, int action, int mode);
    static void Mouse_Button_Callback(GLFWwindow *window, int button, int action, int mods);
    static void Mouse_Position_Callback(GLFWwindow *window, double x, double y);
};

} // namespace opengl_gui_viewer
#endif