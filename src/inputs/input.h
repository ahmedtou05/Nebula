#pragma once
#include <GLFW/glfw3.h>
#define MAX_KEYS 1024
#define MAX_BUTTONS 32

namespace nebula {
    namespace inputs {
        class Input {
            private:
                static bool m_Keys[MAX_KEYS];
                static bool m_MouseButtons[MAX_BUTTONS];
                static double mx, my;
            public:
                static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
                static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
                static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

                static bool isKeyPressed(int key);
                static bool isMouseButtonPressed(int button);
                static void getMousePosition(double& x, double& y);
        };
    }
}