//Include files
#include "tiger_engine.hpp"

//Main method
int main()
{
    //GLFW init and hint methods
    glfwInit();
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    //Create GLFW window
    //Pass glfwGetPrimaryMonitor() as GLFWmonitor pointer object in params to get fullscreen
    GLFWwindow* window = glfwCreateWindow(te::SCREEN_WIDTH, te::SCREEN_HEIGHT, "TigerEngine", NULL, NULL); 
    if (window == NULL)
    {
        std::cout << "ALERT : Failed to instantiate GLFW window." << '\n';
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, te::framebuffer_size_callback);

    //Load all OpenGL function pointers via glad
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        std::cout << "ALERT : Failed to initialise GLAD." << std::endl;
        return -1;
    }

    while (!glfwWindowShouldClose(window))
    {
        //Input
        te::process_input(window);

        /**
         * Rendering commands 
         */
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        /**
         * Swap buffers and poll I/O events
         */
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;
}