#pragma once
#include "../config.h"

struct Shader
{
    uint32_t ID;

    Shader( const char* vertPath, const char* fragPath );
    Shader();

    void use();

    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;   
    void setMat4(const std::string &name, glm::mat4 matrix) const; 
    void setVec4(const std::string &name, glm::vec4 vec) const; 
    void setVec3(const std::string &name, glm::vec3 vec) const; 
};