#include "Viewer.h"

using namespace opengl_gui_viewer;

Viewer::Viewer(GLFWwindow *window, const int size_x, const int size_y)
    : window(window), view_width(size_x), view_height(size_y)
{
    this->camera = new Camera(view_width*0.5, view_height);
}

Viewer::~Viewer()
{
}

int Viewer::Initialize()
{
    // Shader
    shader.initializeFromFile("camera.vs", "camera.fs");

    guiWrapper.Initialize(window);
    guiWrapper.test_GenObject();
    guiWrapper.InitBuffer();

    shader.use();
}

Shader &Viewer::GetShader()
{
    return shader;
}

Camera* Viewer::GetCamera()
{
    return camera;
}



void Viewer::Resize(const int w, const int h)
{
    view_width = w;
    view_height = h;
}

void Viewer::Update()
{
    guiWrapper.UIFrame();
    camera->Update();
    guiWrapper.fluid_solver->Update();
}

void Viewer::DrawFrame()
{

    
    // set up global camera
    shader.setMat4("projection", camera->GetProjectionMatrix());
    shader.setMat4("view", camera->GetViewMatrix());
    shader.setMat4("model", camera->GetModelMatrix());
    glBindVertexArray(guiWrapper.VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
    //glDrawArrays(GL_TRIANGLES, 0, 6);
    glDrawElements(GL_TRIANGLES, 0, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0); // no need to unbind it every time 

    guiWrapper.ApplyDisplayOption();
    guiWrapper.Render();

    //std::cout<<t<<std::endl;
}


