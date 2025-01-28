#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "graphics/window.h"
using namespace std;

int main()
{
    using namespace nebula;
    using namespace graphics;

    Window window("Nebula", 800, 600);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    GLuint vao;
    glGenVertexArrays(1,&vao);
    glBindVertexArray(vao);

    while (!window.closed())
    {
        // std::cout << window.getWidth() << ", " << window.getHeight() << std::endl;
        window.clear();
        glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
        window.update();
    }
} 