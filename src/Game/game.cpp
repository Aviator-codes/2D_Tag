#include "game.h"

void Game::init()
{
    ui.init();
    shader = Shader("../src/shaders/shader/shader.vert", "../src/shaders/shader/shader.frag");
    tex = Texture("../assets/test_tex.png");
    glClearColor(0.3f, 0.7f, 0.8f, 1.0f);
    //glFrontFace(GL_CCW);
    //glCullFace(GL_BACK);

    // framebuffer rectangle
    float vertices[] = {
         1.0f,  1.0f, 0.0f, 1.0f, 1.0f, // top right
         1.0f, -1.0f, 0.0f, 1.0f, 0.0f, // bottom right
        -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, // bottom left
        -1.0f,  1.0f, 0.0f, 0.0f, 1.0f// top left
    };

    unsigned int indices[] =
    {
        0, 1, 3,
        1, 2, 3
    };    

    // send vertex data
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    shader.use();
    tex.setShaderSlot(&shader, "texture_img");
    tex.bind(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

void Game::update(float dt)
{
    // tick
}

void Game::render()
{
    glClear(GL_COLOR_BUFFER_BIT);

    shader.use();
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Game::renderDebugUI()
{
    ui.UIsetup();

    ImGui::Begin("Debug window");
    {
        ImGui::Text("Debug options");
    }
    ImGui::End();

    ui.renderUI();
}

void Game::close()
{
    ui.cleanup();
}

void Game::processInput()
{
    if(glfwGetKey(ui.window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(ui.window, true);
}
