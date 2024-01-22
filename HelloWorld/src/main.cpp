// © 2022, CGVR (https://cgvr.informatik.uni-bremen.de/),
// Author: Andre Mühlenbrock (muehlenb@uni-bremen.de)

// Include the GUI:
#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

// Include OpenGL3.3 Core functions:
#include <glad/glad.h>

// Include GLFW/OpenGL:
#include <GLFW/glfw3.h>

// Include IO utilities:
#include <iostream>

#include <cmath>

/**
 * Initializes the application including the GUI
 */

int main(int, char**)
{
    // Setup window:
    glfwSetErrorCallback([](int error, const char* description) {
        fprintf(stderr, "Glfw Error %d: %s\n", error, description);
    });

    if (!glfwInit())
        return 1;

    // Decide GL+GLSL versions:
    const char* glsl_version = "#version 330 core";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Create window with graphics context:
    GLFWwindow* window = glfwCreateWindow(1090, 560, "Computergrafik 1: Hello World", nullptr, nullptr);
    if (window == nullptr)
        return 1;

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    // Initialize GLAD functions:
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Setup Dear ImGui context:
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls

    // Setup Dear ImGui style:
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer backends:
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    // Load Roboto Font:
    io.Fonts->AddFontFromFileTTF((CMAKE_SOURCE_DIR "/lib/imgui-1.88/misc/fonts/Roboto-Medium.ttf") , 16.0f);

    //measures elapsed time
    float currentTime = 0.0f;

    // Main loop which is executed every frame until the window is closed:
    while (!glfwWindowShouldClose(window))
    {
        currentTime = float(glfwGetTime());

        // Processes all glfw events:
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Get the size of the window:
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);

        // Setup the GL viewport
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.5f+sinf(currentTime*1.24f)/2.f, 0.5f+sinf(currentTime*0.801f)/2.f, 0.5f+sinf(currentTime*1.5f)/2.f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Render the GUI and draw it to the screen:
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // Swap Buffers:
        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

