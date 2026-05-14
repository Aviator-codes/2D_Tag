#include "ui.h"

const char* UI::WIN_NAME = "Window Name";

void UI::init()
{
    // glfw init
    if(!glfwInit())
    {
        std::cerr << "Failed to init glfw!\n";
        exit(EXIT_FAILURE);
    }
    // set error callback
    glfwSetErrorCallback(glfwErrorCallback);

    // simple win hints
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // glfw window
    window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, WIN_NAME, NULL, NULL); 
    if(window == NULL)
    {
        std::cerr << "Failed to open glfw window!\n";
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    // glfw context
    glfwMakeContextCurrent(window);
    // glad loader
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Failed to init glad!\n";
        exit(EXIT_FAILURE);
    }
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);  

    // ImGui context and IO
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;   
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable; 

    // ImGui style
    ImGui::StyleColorsDark();
    // setup glfw and gl inits from imgui
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");
}

void UI::UIsetup()
{
    // Create ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        //* ----DockSpace----
        {        
            // dockspace flags
            ImGuiWindowFlags dockspace_window_flags = ImGuiWindowFlags_NoDocking; // no menubar
            dockspace_window_flags |=   ImGuiWindowFlags_NoTitleBar            | ImGuiWindowFlags_NoCollapse; 
            dockspace_window_flags |=   ImGuiWindowFlags_NoResize              | ImGuiWindowFlags_NoMove;
            dockspace_window_flags |=   ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
            dockspace_window_flags |=   ImGuiWindowFlags_NoBackground;

            // dockspace viewport = main window
            const ImGuiViewport* viewport = ImGui::GetMainViewport();
            ImGui::SetNextWindowPos(viewport->WorkPos);
            ImGui::SetNextWindowSize(viewport->WorkSize);
            ImGui::SetNextWindowViewport(viewport->ID);

            // dockspace styles
            ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
            ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
            ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
            ImGui::PushStyleColor(ImGuiCol_DockingEmptyBg, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));

            // dockspace window
            ImGui::Begin("Dockspace window", nullptr, dockspace_window_flags);
            
            // make current window a dockspace
            ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
            ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), ImGuiDockNodeFlags_None);
            
            // end dockspace window
            ImGui::End();
            ImGui::PopStyleColor(); // to not draw the bg until the dockspace window ends
            ImGui::PopStyleVar(3);
        }
}

void UI::renderUI()
{
    // ImGui Rendering
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        // viewports in ImGui
        if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow* backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }

        
        glfwSwapBuffers(window);
}

void UI::cleanup()
{
    // cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();
}


void glfwErrorCallback(int error, const char *description)
{
    std::cerr << "[GLFW Error]: " << error << "  : \n" << description << "\n";
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
} 