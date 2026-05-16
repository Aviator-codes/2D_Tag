#include "game.h"

void Game::init()
{
    ui.init();
    renderer.init(&ui);
    textures.push_back(Texture("../assets/player.png", false));
    textures.push_back(Texture("../assets/center.png", false));
    textures.push_back(Texture("../assets/player_hitbox.png", false));
    glClearColor(0.2f, 0.4f, 0.7f, 1.0f);
    //* major settings
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    player.tex = &textures[0];
    player.pos = {400, 50};
    player.texSize = 64;
    player.hitbox.size = {player.texSize / 2, player.texSize / 2};
}

float fpsTimer = 0.0f;
int fpsFrames = 0;
void Game::update(float dt)
{
    // update frame rate
    fpsTimer += dt;
    fpsFrames++;
    if(fpsTimer >= 0.25f)
    {
        fps = fpsFrames / fpsTimer;
        fpsTimer = 0.0f;
        fpsFrames = 0;
    }

    // update position from velocity
    player.updatePos(dt);
    // accelerate due to gravity
    player.vel.y += g * dt;

    // screen collision check
    player.screenCollision(windowSize);
}

void Game::render()
{
    glClearColor(backgroundColor.r, backgroundColor.g, backgroundColor.b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    renderer.begin();
    renderer.draw(*player.tex, player.pos.x, player.pos.y, player.texSize, player.texSize);
    if(viewCenter)
    {
        renderer.draw(textures[1], player.pos.x, player.pos.y, 64, 64);
    }
    if(viewHitboxes)
    {
        renderer.draw(textures[2], player.pos.x, player.pos.y, player.texSize, player.texSize);
    }
    renderer.end();
}

void Game::renderDebugUI()
{
    ui.UIsetup();

    ImGui::Begin("Debug window");
    {
        ImGui::Text("Debug options");
        ImGui::Text("FPS : %.2f ( %.5f ms )", fps, 1000.0f / std::max(fps, 0.001f));
        if(ImGui::Checkbox("VSync", &vsync))
        {
            glfwSwapInterval(vsync ? 1 : 0);
        }
        ImGui::Separator();
        ImGui::ColorEdit3("Background", glm::value_ptr(backgroundColor));
        ImGui::Separator();
        ImGui::Checkbox("Show hitboxes", &viewHitboxes);
        ImGui::Checkbox("Show center", &viewCenter);
        ImGui::Separator();
        ImGui::SliderFloat2("Player Position", glm::value_ptr(player.pos), -200.0f, 1000.0f);
        ImGui::SliderFloat2("Player Velocity", glm::value_ptr(player.vel), -200.0f, 1000.0f);
    }
    ImGui::End();

    ui.renderUI();
}

void Game::close()
{
    ui.cleanup();
}

const float moveSpeed = 300.0f;
bool pressedSpace = false;
void Game::processInput()
{
    player.vel.x = 0.0f;

    if(glfwGetKey(ui.window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(ui.window, true);
    if(glfwGetKey(ui.window, GLFW_KEY_A) == GLFW_PRESS)
        player.vel.x -= moveSpeed;
    if(glfwGetKey(ui.window, GLFW_KEY_D) == GLFW_PRESS)
        player.vel.x += moveSpeed;
    if((glfwGetKey(ui.window, GLFW_KEY_SPACE) == GLFW_PRESS || glfwGetKey(ui.window, GLFW_KEY_W) == GLFW_PRESS))
    {
        if(!pressedSpace)
        {
            player.vel.y = -player.jumpHeight;
            pressedSpace = true;
        }
    }
    else
    {
        pressedSpace = false;
    }

}
