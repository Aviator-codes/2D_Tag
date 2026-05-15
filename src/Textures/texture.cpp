#include "texture.h"

Texture::Texture( std::string texFilePath, bool flipVertically )
    : filePath( texFilePath )
{
    GLenum format;
    stbi_set_flip_vertically_on_load( flipVertically );
    std::cout << "Reached texture loader\n";
    uint8_t* data = stbi_load( texFilePath.c_str(), &width, &height, &nrChannels, 0 );
    std::cout << width << ' '
          << height << ' '
          << nrChannels << '\n';
    glGenTextures( 1, &ID );
    glBindTexture( GL_TEXTURE_2D, ID );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,     GL_REPEAT  );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,     GL_REPEAT  );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
    if ( nrChannels == 4 )
        format = GL_RGBA;
    else if( nrChannels == 3 )
        format = GL_RGB;
    else
        format = GL_RED;

    if( data )
    {
        glTexImage2D( GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data );
        glGenerateMipmap( GL_TEXTURE_2D );
    }
    else
    {
        LogError( std::string("Failed to load texture: ") + filePath );
    }
    stbi_image_free( data );
}

void Texture::setShaderSlot(Shader *shader, const std::string& texUniform, uint slot)
{
    shader->setInt( texUniform, slot );
}

void Texture::bind( uint slot )
{
    glActiveTexture( GL_TEXTURE0 + slot );
    glBindTexture( GL_TEXTURE_2D, ID );
}

Texture::~Texture()
{
    if( ID != 0 )
        glDeleteTextures( 1, &ID );
}

Texture::Texture(Texture&& other) noexcept
{
    ID = other.ID;
    width = other.width;
    height = other.height;
    nrChannels = other.nrChannels;
    filePath = std::move(other.filePath);

    other.ID = 0;
}

Texture& Texture::operator=(Texture&& other) noexcept
{
    if (this != &other)
    {
        if (ID != 0)
            glDeleteTextures(1, &ID);

        ID = other.ID;
        width = other.width;
        height = other.height;
        nrChannels = other.nrChannels;
        filePath = std::move(other.filePath);

        other.ID = 0;
    }
    return *this;
}