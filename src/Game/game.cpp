#include "game.h"

void Game::init()
{
    ui.init();
    renderer.init(&ui);
    tex = Texture("../assets/debug.png", false);
    glClearColor(0.2f, 0.4f, 0.7f, 1.0f);
}

void Game::update(float dt)
{
    // tick
}

void Game::render()
{
    glClear(GL_COLOR_BUFFER_BIT);
    renderer.begin();
    renderer.draw(tex, 0, 0, 128, 128);
    renderer.end();
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
