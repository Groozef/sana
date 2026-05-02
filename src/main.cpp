#define GLFW_INCLUDE_NONE

#include <iostream>
#include <GLFW/glfw3.h>

int main()
{
    try
    {
        if (!glfwInit())
        {
            throw std::runtime_error("Failed to initialize GLFW");
        }
        GLFWwindow *window = glfwCreateWindow(1280, 720, "SANA v0.0.1", nullptr, nullptr);

        if (!window)
        {
            throw std::runtime_error("Failed to create Window");
        }
        glfwMakeContextCurrent(window);


        while (!glfwWindowShouldClose(window))
        {
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