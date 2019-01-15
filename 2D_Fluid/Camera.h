
// @yanshi
//#####################################################################
// Class OGL_Camera
//######################################################################
#ifndef OGL_CAMERA_
#define OGL_CAMERA_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace opengl_gui_viewer
{

// class Viewer;

class Camera
{
  public:
    Camera(const int size_x, const int size_y)
        : Position(glm::vec3(0.0f, 0.0f, -3.0f)),
          Front(glm::vec3(0.0f, 0.0f, 1.0f)),
          Up(glm::vec3(0.0f, 1.0f, 0.0f)),
          WorldUp(glm::vec3(0.0f, 0.0f, 1.0f)),
          Position_Delta(glm::vec3(0.0f, 0.0f, 0.0f)),
          MovementSpeed(1.0f), Move_Camera(false),
          Yaw(-90.0f), Pitch(0.0f), Fov(45.0f), Heading(0.0f),
          Screen_Width(size_x), Screen_Height(size_y)
    {
    }
    ~Camera()
    {
    }

    // Parent Viewer
    // Viewer *viewer;

    glm::vec3 Position, Front, Up, Right;
    glm::vec3 Position_Delta, Mouse_Position;
    glm::vec3 WorldUp;

    GLfloat Yaw;
    GLfloat Pitch;

    GLfloat deltaTime, lastFrame, currentFrame;
    GLfloat MovementSpeed;
    GLfloat Fov;
    GLfloat Heading;

    bool Move_Camera;

    glm::mat4 projection, view, model, MVP;

    int Screen_Width, Screen_Height;

    glm::mat4 GetViewMatrix() { return view; }
    glm::mat4 GetProjectionMatrix() { return projection; }
    glm::mat4 GetModelMatrix() { return model; }
    glm::mat4 GetMatrix() { return MVP; }

    // TODO
    void test_modification()
    {
        glm::vec3 cubePositions[] = {
            glm::vec3(0.5f, 0.5f, 0.0f)};
        model = glm::translate(model, cubePositions[0]);
        float angle = 20.0f * 0;
        model = glm::rotate(model, glm::radians(angle), glm::vec3(0.0f, 0.0f, 1.0f));
    }

    GLfloat GetCameraSpeed()
    {
        // currentFrame = glfwGetTime();
        // deltaTime = currentFrame - lastFrame;
        // lastFrame = currentFrame;

        // return MovementSpeed * deltaTime;

        // TODO

        return 0.05;
    }

    void Update()
    {
        view = glm::lookAt(Position, Position + Front, Up);
        projection = glm::perspective(glm::radians(Fov), (float)Screen_Width / (float)Screen_Height, 0.1f, 100.0f);
        model = glm::mat4(1.0f);

        MVP = projection * view * model;
    }

    void ProcessMouseScroll(GLfloat yoffset)
    {
        if (this->Fov >= 1.0f && this->Fov <= 45.0f)
            this->Fov -= yoffset;
        if (this->Fov <= 1.0f)
            this->Fov = 1.0f;
        if (this->Fov >= 45.0f)
            this->Fov = 45.0f;
    }

    void Change_Pitch(float degrees)
    {
        // check bounds with the max pitch rate so that we are not moving too fast
        if (degrees < -5)
            degrees = -5;
        else if (degrees > 5)
            degrees = 5;

        this->Pitch += degrees * 0.02f;

        // check bounds for the camera pitch
        if (this->Pitch > 360.0f)
            this->Pitch -= 360.0f;
        else if (this->Pitch < -360.0f)
            this->Pitch += 360.0f;
    }
    //#####################################################################
    // Change_Heading
    //#####################################################################
    void Change_Heading(float degrees)
    {
        // check bounds with the max heading rate so that we are not moving too fast
        if (degrees < -5)
            degrees = -5;
        else if (degrees > 5)
            degrees = 5;

        // this controls how the heading changes if the camera is pointed straight up or down
        // the heading delta direction changes
        if ((this->Pitch > 90 && this->Pitch < 270) || (this->Pitch < -90 && this->Pitch > -270))
            this->Heading -= degrees * 0.02f;
        else
            this->Heading += degrees * 0.02f;

        // check bounds for the camera heading
        if (this->Heading > 360.0f)
            this->Heading -= 360.0f;
        else if (this->Heading < -360.0f)
            this->Heading += 360.0f;
    }

    void Move_2D(int x, int y)
    {
        // compute the mouse delta from the previous mouse position
        glm::vec3 Mouse_Delta = Mouse_Position - glm::vec3(x, y, 0);
        // if the camera is moving, meaning that the mouse was clicked and dragged,
        // change the pitch and heading
        if (Move_Camera)
        {
            std::cout << Mouse_Delta.x << "\t" << Mouse_Delta.y << std::endl;

            // Change_Heading(.08f * Mouse_Delta.x);
            // Change_Pitch(Mouse_Delta.y);

            Yaw += .08f * Mouse_Delta.x;
            Pitch += .08f * Mouse_Delta.y;

            glm::vec3 front;
            front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
            front.y = sin(glm::radians(Pitch));
            front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
            Front = glm::normalize(front);

            Update();
        }
        Mouse_Position = glm::vec3(x, y, 0);
    }

    void Set_Pos(int button, int state, int x, int y)
    {
        if (button == 3 && state == GLFW_PRESS)
            this->Position_Delta += this->Up * .05f;
        else if (button == 4 && state == GLFW_PRESS)
            this->Position_Delta -= this->Up * .05f;
        else if (button == GLFW_MOUSE_BUTTON_LEFT && state == GLFW_PRESS)
            Move_Camera = true;
        else if (button == GLFW_MOUSE_BUTTON_LEFT && state == GLFW_RELEASE)
            Move_Camera = false;

        Mouse_Position = glm::vec3(x, y, 0);
    }
};
} // namespace opengl_gui_viewer

#endif