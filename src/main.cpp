#include "config.h"
#include "Game/game.h"

int main(int argc, char** argv)
{
    Game game;
    game.init();

    float dt = 0;
    double last = glfwGetTime();
    while(!glfwWindowShouldClose(game.ui.window))
    {
        // calculate dt
        double current = glfwGetTime();
        dt = current - last;
        last = current;

        // TODO: Inputs
        game.processInput();

        
        //* Main Window Rendering
        game.update(dt);
        game.render();
        
        glfwPollEvents();
        game.renderDebugUI();
    }
    
    game.close();
    return 0;
}