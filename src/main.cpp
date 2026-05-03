#define GLFW_INCLUDE_NONE

#include <iostream>
#include <GLFW/glfw3.h>
#include <glad/gl.h>

int main()
{
    try
    {
        if (!glfwInit())
        {
            throw std::runtime_error("ERROR: GLFW INIT(). Failed to initialize GLFW");
        }
        GLFWwindow *window = glfwCreateWindow(1280, 720, "SANA v0.0.1", nullptr, nullptr);

        if (!window)
        {
            throw std::runtime_error("ERROR: GLFW. Failed to create Window");
        }
        glfwMakeContextCurrent(window);

        if (!gladLoadGL(glfwGetProcAddress))
        {
            throw std::runtime_error("ERROR: GLADLOAD. Failed initializing the bridge with the graphics card driver");
        }

        while (!glfwWindowShouldClose(window))
        {
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            glfwSwapBuffers(window);
            glfwPollEvents();
        }
        glfwDestroyWindow(window);
        glfwTerminate();
    }
    catch (const std::exception &err)
    {
        std::cerr << "Error: " << err.what() << std::endl;
        glfwTerminate();
        return -1;
    }
    return 0;
}