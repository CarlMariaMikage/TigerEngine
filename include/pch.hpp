#pragma once

/** 
 * Precompiled header
 * 
 * --------------------
 * 
 * N.B. USE FOR C++ FILES ONLY
 * 
 * - Saves time during compilation.
 * - Helps make header and source files more organised.
 * 
 *  **/

// Standard libraries
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <thread>

// OpenGL libraries
#include <glad/glad.h> // NB: THIS HAS TO COME BEFORE GLFW is included OTHERWISE THE WHOLE BUILD PROCESS FKING BREAKS
#include <GLFW/glfw3.h>