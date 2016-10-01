#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

void key_callback(GLFWwindow * window, int key, int scancode, int action, int mode)
{
  if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GL_TRUE);
}

int main()
{
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);   // version 3.3
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  // using core opengl profile (that means modern opengl)
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // make mac os x happy
  
  // creating the window
  GLFWwindow * window = glfwCreateWindow(800, 600, "Learn OpenGL", nullptr, nullptr);
  if(window == nullptr)
    {
      std::cout << "failed to create window" << std::endl;
      glfwTerminate();
      return -1;
    }
  glfwMakeContextCurrent(window);
  glViewport(0, 0, 800, 600);

  // initializing glew (DO IT AFTER CREATING THE WINDOW)
  glewExperimental = GL_TRUE;
  if(glewInit() != GLEW_OK)
    {
      std::cout << "Failed to initialize GLEW" << std::endl;
      return -1;
    }


  while(!glfwWindowShouldClose(window))
    {
      //check and call events
      glfwPollEvents();
      glfwSetKeyCallback(window, key_callback);

      // render everything here
      // ...
      glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);

      
      //swap buffers
      glfwSwapBuffers(window);
    }

  glfwTerminate();
  return 0;
}
