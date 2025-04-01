#pragma once
#include "../CommonHeader.h"

class Shader 
{
    public: 

        GLuint ID;
        
        Shader(const char* vertexPath ,const char* fragmentPath);

        void use();
        void SetBool(const std::string& name, bool value) const;
        void SetInt(const std::string& name, int value) const;
        void SetFloat(const std::string& name, float value) const;
        void SetVec3(const std::string& name, const glm::vec3& value) const;
        void SetMat(const std::string&name, const glm::mat4& matrix) const;
    
    private:

     std::string vertexCode;
     std::string fragmentCode;
     std::ifstream vShaderFile;
     std::ifstream fShaderFile;
};
