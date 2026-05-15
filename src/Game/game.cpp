#include "game.h"

void Game::init()
{
    ui.init();
    renderer.init(&ui);
    textures.push_back(Texture("../assets/player.png", false));
    glClearColor(0.2f, 0.4f, 0.7f, 1.0f);
    //* major settings
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    player.tex = &textures[0];
    player.pos = glm::vec2(400, 300);
    player.speed = 300.0f;
}

void Game::update(float dt)
{
    player.updatePos(dt);
}

void Game::render()
{
    glClearColor(backgroundColor.r, backgroundColor.g, backgroundColor.b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    renderer.begin();
    renderer.draw(*player.tex, player.pos.x, player.pos.y, 128, 128);
    renderer.end();
}

void Game::renderDebugUI()
{
    ui.UIsetup();

    ImGui::Begin("Debug window");
    {
        ImGui::Text("Debug options");
        ImGui::ColorEdit3("Background", glm::value_ptr(backgroundColor));
    }
    ImGui::End();

    ui.renderUI();
}

void Game::close()
{
    ui.cleanup();
}

void Game::processInput(float dt)
{
    player.vel = {0.0f, 0.0f};

    if(glfwGetKey(ui.window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(ui.window, true);
    if(glfwGetKey(ui.window, GLFW_KEY_W) == GLFW_PRESS)
        player.vel.y -= 1;
    if(glfwGetKey(ui.window, GLFW_KEY_S) == GLFW_PRESS)
        player.vel.y += 1;
    if(glfwGetKey(ui.window, GLFW_KEY_A) == GLFW_PRESS)
        player.vel.x -= 1;
    if(glfwGetKey(ui.window, GLFW_KEY_D) == GLFW_PRESS)
        player.vel.x += 1;

    if(glm::length(player.vel) > 0)
        player.vel = glm::normalize(player.vel);
}
