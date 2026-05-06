#define GLFW_INCLUDE_NONE

#include <iostream>
#include <GLFW/glfw3.h>
#include <glad/gl.h>
#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

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

        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO &io = ImGui::GetIO();
        ImGui::StyleColorsDark();
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 330 core");

        while (!glfwWindowShouldClose(window))
        {
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();
            ImGui::ShowDemoWindow();
            ImGui::Render();

            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();

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