#include "input.h"
#include <iostream>

namespace nebula {
    namespace inputs {
        bool Input::m_Keys[MAX_KEYS] = { false };
        bool Input::m_MouseButtons[MAX_BUTTONS] = { false };
        double Input::mx = 0.0;
        double Input::my = 0.0;

        void Input::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
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

        void Input::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
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
        
        void Input::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
        {
            mx = xpos;
            my = ypos;
        }

        bool Input::isKeyPressed(int key)
        {
            return m_Keys[key];
        }
        
        bool Input::isMouseButtonPressed(int button)
        {
            return m_MouseButtons[button];
        }

        void Input::getMousePosition(double& x, double& y)
        {
            x = mx;
            y = my;
        }
    }
}