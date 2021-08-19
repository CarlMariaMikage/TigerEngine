#pragma once

#include "pch.hpp"

namespace te
{

//Definitions
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void process_input(GLFWwindow* window);

//Settings
const unsigned int SCREEN_WIDTH     = 800;
const unsigned int SCREEN_HEIGHT    = 600;

}