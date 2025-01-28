#pragma once
#define GLEW_STATIC
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace nebula { 
    namespace graphics {
        class Window {
            private:
                const char* m_title;
                int m_width, m_height;
                GLFWwindow* m_window;
                bool m_closed;
            public:
                Window(const char* title, int width, int height);
                ~Window();
                bool closed() const;
                void update();
                GLFWwindow* getGLFWWindow() const;
                void clear() const;

                inline int getWidth() const {return m_width;}
                inline int getHeight() const {return m_height;}
            private:
                bool init();
                
        
        };
    }

}