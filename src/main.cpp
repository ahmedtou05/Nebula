#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "graphics/window.h"
#include "inputs/input.h"
#include "maths/maths.h"
using namespace std;

// TODO: log system!

int main()
{
    using namespace nebula;
    using namespace graphics;
    using namespace inputs;
    using namespace maths;

    Window window("Nebula", 800, 600);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    vect2 vector1(1.0f, 2.0f);
    vect2 vector2(1.0f, 1.0f);

    while (!window.closed())
    {
        window.clear();
        std::cout << vector1 << std::endl;
        

        window.update();
    }
} 