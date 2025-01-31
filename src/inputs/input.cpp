#include "input.h"
#include <iostream>

namespace nebula {
    namespace inputs {
        bool input::m_Keys[MAX_KEYS] = { false };
        bool input::m_MouseButtons[MAX_BUTTONS] = { false };
        double input::mx = 0.0;
        double input::my = 0.0;

        void input::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            if (key >= 0 && key < MAX_KEYS)
            {
                if (action == GLFW_PRESS)
                {
                    m_Keys[key] = true;
                }
                else if (action == GLFW_RELEASE)
                {
                    m_Keys[key] = false;
                }
            }
        }

        void input::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
        {
            if (button >= 0 && button < MAX_BUTTONS)
            {
                if (action == GLFW_PRESS)
                {
                    m_MouseButtons[button] = true;
                }
                else if (action == GLFW_RELEASE)
                {
                    m_MouseButtons[button] = false;
                }
            }
        }
        
        void input::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
        {
            mx = xpos;
            my = ypos;
        }

        bool input::isKeyPressed(int key)
        {
            return m_Keys[key];
        }
        
        bool input::isMouseButtonPressed(int button)
        {
            return m_MouseButtons[button];
        }

        void input::getMousePosition(double& x, double& y)
        {
            x = mx;
            y = my;
        }
    }
}