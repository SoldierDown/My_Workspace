#include "World.h"

using namespace opengl_gui_viewer;

World::World(int size_x, int size_y)
    : window(nullptr), viewer(nullptr),
      window_width(size_x), window_height(size_y)
{
}

World::~World()
{
    if (window)
    {
        glfwTerminate();
        window = NULL;
    }
    if (viewer)
        delete viewer;
}

void World::Initialize()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    window = glfwCreateWindow(window_width, window_height, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);

    
    glfwSwapInterval(0);

    glewExperimental = GL_TRUE; 
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Failed to initialize GLEW!" << std::endl;
        return;
    }

    glfwSetWindowCloseCallback(window, Close_Callback);
    glfwSetFramebufferSizeCallback(window, Reshape_Callback);
    glfwSetKeyCallback(window, Keyboard_Callback);
    glfwSetMouseButtonCallback(window, Mouse_Button_Callback);
    glfwSetCursorPosCallback(window, Mouse_Position_Callback);
    glfwSetScrollCallback(window, Scroll_Callback);
    glfwGetFramebufferSize(window, &window_width, &window_height);

    glfwSetWindowUserPointer(window, this); 
    this->viewer = new Viewer(window, window_width, window_height);
}

void World::Main_Loop()
{
    Initialize_Viewer();
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glEnable(GL_DEPTH_TEST);
        viewer->Update();
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        viewer->DrawFrame();
        glfwSwapBuffers(window);
    }
}

void World::Initialize_Viewer()
{
    viewer->Initialize();
}


void World::Close_Callback(GLFWwindow *window)
{
    glfwSetWindowShouldClose(window, GL_TRUE);
}

void World::Scroll_Callback(GLFWwindow *window, double xoffset, double yoffset)
{
    World *world = static_cast<World *>(glfwGetWindowUserPointer(window));
    world->viewer->GetCamera()->ProcessMouseScroll(yoffset);

    
}

void World::Reshape_Callback(GLFWwindow *window, int w, int h)
{
    World *world = static_cast<World *>(glfwGetWindowUserPointer(window));
    world->window_width = w;
    world->window_height = h;
    world->viewer->Resize(w,h);
}

void World::Keyboard_Callback(GLFWwindow *window, int key, int scancode, int action, int mode)
{
    World *world = static_cast<World *>(glfwGetWindowUserPointer(window));
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

    float camVel = world->viewer->guiWrapper.GetIOFramerate() / 50000.0;


    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        world->viewer->GetCamera()->Position += camVel * world->viewer->GetCamera()->Front;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        world->viewer->GetCamera()->Position -= camVel * world->viewer->GetCamera()->Front;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        world->viewer->GetCamera()->Position -= glm::normalize(glm::cross(world->viewer->GetCamera()->Front, world->viewer->GetCamera()->Up)) * camVel;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        world->viewer->GetCamera()->Position += glm::normalize(glm::cross(world->viewer->GetCamera()->Front, world->viewer->GetCamera()->Up)) * camVel;

    
    

    


}

void World::Mouse_Button_Callback(GLFWwindow *window, int button, int action, int mods)
{
    World *world = static_cast<World *>(glfwGetWindowUserPointer(window));
    world->mouse_position = world->viewer->guiWrapper.GetMousePosition();

    if(world->mouse_position[0]<world->window_width * 0.5)
    {

    }

    
    else
    {
        
    }
    

}

void World::Mouse_Position_Callback(GLFWwindow *window, double x, double y)
{
    World *world = static_cast<World *>(glfwGetWindowUserPointer(window));
    if(world->mouse_position[0]<world->window_width * 0.5)
    {

    }

    
    else
    {
        
    }
}
