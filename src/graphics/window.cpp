#include "window.h"


namespace nebula { 
    namespace graphics{

        void windowResize(GLFWwindow* window, int width, int height);
        Window::Window(const char* title, int width, int height)
        :m_title(title) , m_width(width), m_height(height){
            
            if (!init())
                glfwTerminate();
        }
        Window::~Window()
        {
            glfwTerminate();
        }

        bool Window::init()
        {
            if (!glfwInit())
            {
                std::cout << "Failed to initialize GLFW!" << std::endl;
                return false;
            } 
            std::cout << "GLFW initialized successfully" << std::endl;

            m_window = glfwCreateWindow(m_width, m_height, m_title, nullptr, nullptr);
            if (!m_window)
            {
                std::cout << "Failed to create GLFW window" << std::endl;
                return false;
            }
            std::cout << "Window created successfully" << std::endl;

            glfwMakeContextCurrent(m_window);
            glfwSetWindowSizeCallback(m_window, windowResize);

            std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;

            if (glewInit() != GLEW_OK)
            {
                std::cout << "Failed to initialize GLEW!" << std::endl;
                return false;
            }
            std::cout << "GLEW initialized successfully" << std::endl;

            return true;

        }

        void Window::update()
        {
            glfwPollEvents();
            glfwSwapBuffers(m_window);
        }

        void Window::clear() const
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

        bool Window::closed() const
        {
            return glfwWindowShouldClose(m_window);
        }
        void windowResize(GLFWwindow* window, int width, int height)
        {
            glViewport(0, 0, width, height);
        }
    } 
}