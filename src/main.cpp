#include "config.h"
#include "Game/game.h"

int main(int argc, char** argv)
{
    Game game;
    game.init();

    float dt = 0;
    while(!glfwWindowShouldClose(game.ui.window))
    {
        // TODO: Inputs
        game.processInput();
        // calculate dt
        
        //* Main Window Rendering
        game.update(dt);
        game.render();
        
        glfwPollEvents();
        game.renderDebugUI();
    }
    
    game.close();
    return 0;
}