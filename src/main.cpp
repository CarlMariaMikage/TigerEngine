//Include files
#include "tiger_engine.hpp"

namespace te 
{
    const char *vertex_shader_source = "#version 460 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";
    const char *fragment_shader_source = "#version 460 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "}\n\0";
    const char *fragment_shader_source_cyan = "#version 460 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "   FragColor = vec4(0.0f, 1.0f, 1.0f, 1.0f);\n"
        "}\n\0";
}

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

    /**
     * Compile vertex shader source code
     * **/
    unsigned int vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &te::vertex_shader_source, NULL);
    glCompileShader(vertex_shader);

    int  success;
    char infoLog[512];
    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertex_shader, 512, NULL, infoLog);
        std::cout << "ALERT : Vertex shader compilation unsuccessful.\n" << infoLog << std::endl;
    }
    
    /**
     * Compile fragment shader source code
     * **/
    unsigned int fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &te::fragment_shader_source, NULL);
    glCompileShader(fragment_shader);

    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragment_shader, 512, NULL, infoLog);
        std::cout << "ALERT : Fragment shader compilation unsuccessful.\n" << infoLog << std::endl;
    }

    unsigned int fragment_shader_cyan = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader_cyan, 1, &te::fragment_shader_source_cyan, NULL);
    glCompileShader(fragment_shader_cyan);

    glGetShaderiv(fragment_shader_cyan, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragment_shader_cyan, 512, NULL, infoLog);
        std::cout << "ALERT : Fragment shader compilation unsuccessful.\n" << infoLog << std::endl;
    }

    /**
     * Link shader programs
     * **/
    unsigned int shader_program = glCreateProgram();
    glAttachShader(shader_program, vertex_shader);
    glAttachShader(shader_program, fragment_shader);
    glLinkProgram(shader_program);

    glGetProgramiv(shader_program, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shader_program, 512, NULL, infoLog);
        std::cout << "ALERT : Shader program linking unsuccessful.\n" << infoLog << std::endl;
    }

    unsigned int shader_program_cyan = glCreateProgram();
    glAttachShader(shader_program_cyan, vertex_shader);
    glAttachShader(shader_program_cyan, fragment_shader_cyan);
    glLinkProgram(shader_program_cyan);

    glGetProgramiv(shader_program_cyan, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shader_program_cyan, 512, NULL, infoLog);
        std::cout << "ALERT : Shader program linking unsuccessful.\n" << infoLog << std::endl;
    }

    glDeleteShader(vertex_shader); glDeleteShader(fragment_shader); glDeleteShader(fragment_shader_cyan);
    
    /**
     * Vertex array, vertex buffer and element buffer config
     * **/
    float triangle1[] = {
        
        -0.9f, -0.5f, 0.0f,  // left 
        -0.0f, -0.5f, 0.0f,  // right
        -0.45f, 0.5f, 0.0f,  // top 
    }; 
    
    float triangle2[] = {
         0.0f, -0.5f, 0.0f,  // left
         0.9f, -0.5f, 0.0f,  // right
         0.45f, 0.5f, 0.0f   // top 
    };
    unsigned int VBO[2], VAO[2];
    glGenVertexArrays(2, VAO);
    glGenBuffers(2, VBO);

    //triangle 1
    glBindVertexArray(VAO[0]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle1), triangle1, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    //triangle 2
    glBindVertexArray(VAO[1]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle2), triangle2, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    while (!glfwWindowShouldClose(window))
    {
        /**
         * Input
         */
        te::process_input(window);

        /**
         * Render
         */
        //71, 37, 143
        glClearColor(0.071f, 0.037f, 0.143f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shader_program);
        glBindVertexArray(VAO[0]);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glUseProgram(shader_program_cyan);
        glBindVertexArray(VAO[1]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        /**
         * Swap buffers and poll I/O events
         */
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    //Termination and deallocation
    glDeleteVertexArrays(2, VAO);
    glDeleteBuffers(2, VBO);
    glDeleteProgram(shader_program); glDeleteProgram(shader_program_cyan);

    glfwTerminate();
    return 0;
}