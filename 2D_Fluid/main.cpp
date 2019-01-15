#include "World.h"

using namespace opengl_gui_viewer;

int main(int argc, char const *argv[])
{
    World world(800, 600);
    world.Initialize();
    world.Main_Loop();

    return 0;
}
