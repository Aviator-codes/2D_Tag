#pragma once
#include "../config.h"
#include "stb_image.h"
#include "../shaders/shader.h"

struct Texture
{
    uint ID = 0;
    int  width = 0, height = 0, nrChannels = 0;
    std::string filePath;

    Texture() = default;
    Texture( std::string texFilePath, bool flipVertically = true );

    Texture(const Texture&) = delete;
    Texture& operator=(const Texture&) = delete;

    Texture(Texture&& other) noexcept;
    Texture& operator=(Texture&& other) noexcept;

    void setShaderSlot( Shader* shader, const std::string& texUniform, uint slot = 0 );

    void bind( uint slot = 0 );

    ~Texture();
};