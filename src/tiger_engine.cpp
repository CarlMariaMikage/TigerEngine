#include "tiger_engine.hpp"

namespace te
{

//Whenever the window is resized, framebuffer_size_callback is executed 
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    //Ensure that viewport matches the new window dimensions
    glViewport(0, 0, width, height);
}

//Map input keys to specific functionality
void process_input(GLFWwindow* window)
{
    //Map ESC key to WindowShouldClose functionality
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
}

}