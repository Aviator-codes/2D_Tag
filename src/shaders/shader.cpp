#include "shader.h"

Shader::Shader(const char *vertPath, const char *fragPath)
{
    std::ifstream vSrcFile( vertPath );
    std::ifstream fSrcFile( fragPath );
    std::stringstream vShaderStream;
    std::stringstream fShaderStream;

    
    vShaderStream << vSrcFile.rdbuf();
    fShaderStream << fSrcFile.rdbuf();

    //std::cout << vShaderStream.str() << '\n';
    //std::cout << fShaderStream.str() << '\n';

    vSrcFile.close();
    fSrcFile.close();

    std::string vShaderCode = vShaderStream.str();
    std::string fShaderCode = fShaderStream.str();
    const char* vShaderSrc = vShaderCode.c_str();
    const char* fShaderSrc = fShaderCode.c_str();

    uint vertex, fragment;
    int success;
    char infoLog[512];  

    vertex = glCreateShader( GL_VERTEX_SHADER );
    glShaderSource( vertex, 1, &vShaderSrc, NULL );
    glCompileShader( vertex );
    glGetShaderiv( vertex, GL_COMPILE_STATUS, &success );
    if( !success )
    {
        glGetShaderInfoLog( vertex, 512, NULL, infoLog );
        LogError( "Failed to compile Vertex Shader" );
        std::cout << infoLog << "\n";
    }
    
    fragment = glCreateShader( GL_FRAGMENT_SHADER );
    glShaderSource( fragment, 1, &fShaderSrc, NULL );
    glCompileShader( fragment );
    glGetShaderiv( fragment, GL_COMPILE_STATUS, &success );
    if( !success )
    {
        glGetShaderInfoLog( fragment, 512, NULL, infoLog );
        LogError( "Failed to compile Fragment Shader" );
        std::cout << infoLog << "\n";
    }

    ID = glCreateProgram();
    glAttachShader( ID, vertex );
    glAttachShader( ID, fragment );
    glLinkProgram( ID );
    glGetProgramiv( ID, GL_LINK_STATUS, &success );
    if( !success )
    {
        glGetProgramInfoLog( ID, 512, NULL, infoLog );
        LogError( "Failed to Link Shaders" );
        std::cout << infoLog << "\n";
    }

    glDeleteShader( vertex );
    glDeleteShader( fragment );
}

Shader::Shader() : ID(0) {}

void Shader::use()
{
    glUseProgram( ID );
}

void Shader::setBool(const std::string &name, bool value) const
{
    glUniform1i( glGetUniformLocation( ID, name.c_str() ), (int)value );
}

void Shader::setInt(const std::string &name, int value) const
{
    glUniform1i( glGetUniformLocation( ID, name.c_str() ), value );
}

void Shader::setFloat(const std::string &name, float value) const
{
    glUniform1f( glGetUniformLocation( ID, name.c_str() ), value );
}

void Shader::setMat4(const std::string &name, glm::mat4 matrix) const
{
    glUniformMatrix4fv( glGetUniformLocation( ID, name.c_str() ), 1, GL_FALSE, glm::value_ptr(matrix) );
}

void Shader::setVec4(const std::string &name, glm::vec4 vec) const
{
    glUniform4fv( glGetUniformLocation( ID, name.c_str() ), 1, glm::value_ptr( vec ) );
}

void Shader::setVec3(const std::string &name, glm::vec3 vec) const
{
    glUniform3fv( glGetUniformLocation( ID, name.c_str() ), 1, glm::value_ptr( vec ) );
}
