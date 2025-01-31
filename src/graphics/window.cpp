#include "window.h"
#include "../inputs/input.h"


namespace nebula { 
    namespace graphics{
        using namespace inputs;

        void windowResize(GLFWwindow* window, int width, int height);
        Window::Window(const char* title, int width, int height)
        {
            m_Title = title;
            m_Width = width;
            m_Height = height;
            if(!init())
                glfwTerminate();
            
            glfwSetKeyCallback(m_window, Input::key_callback);
            glfwSetMouseButtonCallback(m_window, Input::mouse_button_callback);
            glfwSetCursorPosCallback(m_window, Input::cursor_position_callback);
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

            m_window = glfwCreateWindow(m_Width, m_Height, m_Title, nullptr, nullptr);
            if (!m_window)
            {
                std::cout << "Failed to create GLFW window! " << std::endl;
                return false;
            }
            std::cout << "Window created successfully" << std::endl;

            glfwMakeContextCurrent(m_window);
            glfwSetWindowSizeCallback(m_window, windowResize);


            if (glewInit() != GLEW_OK)
            {
                std::cout << "Failed to initialize GLEW!" << std::endl;
                return false;
            }
            std::cout << "GLEW initialized successfully" << std::endl;

            std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;
            return true;

        }

        void Window::clear() const
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

        void Window::update()
        {
            glfwPollEvents();
            glfwSwapBuffers(m_window);
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