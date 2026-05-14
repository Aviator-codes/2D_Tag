#include "../config.h"
#include "../UI/ui.h"
#include "../shaders/shader.h"
#include "../Textures/texture.h"

struct Game
{
    void init();
    void update(float dt);
    void render();
    void renderDebugUI();
    void close();
    void processInput();
    UI ui;
    Shader shader; 
    Texture tex;
    uint VAO, VBO, EBO;
}; 