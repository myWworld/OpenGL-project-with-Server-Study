#include "shader.h"

Shader::Shader(const char* vertexPath, const char* fragmentPath) {

    std::ifstream vFile(vertexPath);
    std::ifstream fFile(fragmentPath);

    std::stringstream VStream, FStream;
    
    VStream << vFile.rdbuf();
    FStream << fFile.rdbuf();

    std::string vCode = VStream.str();
    std::string fCode = FStream.str();

    const char* vShaderCode = vCode.c_str();
    const char* fShaderCode = fCode.c_str();

    GLuint vertex = glCreateShader(GL_VERTEX_SHADER); //버텍스 셰이더 객체 생성성
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);
    
    GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);//프래그먼트 셰이더 객체 생성성
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);

    ID = glCreateProgram(); //셰이더 프로그램 객체 생성성
    glAttachShader(ID, vertex); //프로그램에 버텍스 셰이더 추가
    glAttachShader(ID, fragment); //프로그램에 프래그먼트 셰이더 추가
    glLinkProgram(ID); //연결된 셰이더들을 하나의 실행 가능한 프로그램으로 연결결

    glDeleteShader(vertex); //컴파일 후 사용하지 않는 셰이더 객체 삭제
    glDeleteShader(fragment);
}   
  void Shader::use()
  {
    glUseProgram(ID);
  }
 void Shader::SetBool(const std::string& name, bool value) const
  {
      glUniform1i(glGetUniformLocation(ID, name.c_str()),(int)value);
  }
  void Shader::SetInt(const std::string& name, int value) const
  {
        glUniform1i(glGetUniformLocation(ID,name.c_str()), value);
  }
  void Shader::SetFloat(const std::string& name, float value) const
  {
        glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
  }
  void Shader::SetVec3(const std::string& name, const glm::vec3& value) const
  {
        glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, glm::value_ptr(value));
  }
  void Shader::SetMat(const std::string&name, const glm::mat4& matrix) const
  {
        glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()),1,GL_FALSE, glm::value_ptr(matrix));  
  }
