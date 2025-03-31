#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

const char* vertexShaderSource = R"(
  #version 330 core
  layout (location = 0) in vec3 aPos;

  void main()
  {
    gl_Position = vec4(aPos, 1.0);
  }
)";

const char* fragmentShaderSource = R"(
  #version 330 core
  out vec4 FragColor;

  void main()
  {
    FragColor = vec4(1.0, 0.2, 0.2, 1.0);
  }
)";

int main()
{
    if(!glfwInit())
    {
      std::cerr << "Failed to initialize GLFW\n";

      return -1;
    }

    int windowWidth = 800;
    int windowHeight = 600;

    GLFWwindow* window = glfwCreateWindow(windowWidth,windowHeight, "OpenGL ShootingGame"
          ,nullptr, nullptr); //Create window

    if(!window)
    {
      std::cerr << "Failed to create GLFW window\n";
      glfwTerminate();
      return -1;
    }

    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Failed to initalize GLAD\n";
        return -1;
    }

  //  std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;

    glViewport(0,0,windowWidth, windowHeight);

    while(!glfwWindowShouldClose(window))
    {
        glClearColor(0.2f,0.3f,0.3f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
      
    glfwDestroyWindow(window);
    glfwTerminate();

  return 0;
}



