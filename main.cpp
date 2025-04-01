#include "src/CommonHeader.h"
#include "src/shader/shader.h"


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

    Shader shader("src/shader/shaders/vertex.glsl", "src/shader/shaders/fragment.glsl");
    shader.use();
    
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



