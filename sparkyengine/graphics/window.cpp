#include "window.h"

namespace sparky
{
  namespace graphics
  {

    void windowResize(GLFWwindow * window, int width, int height);
    
    Window::Window(const char * name, int width, int height)
    {
      this->name = name;
      this->width = width;
      this->height = height;

      this->init();
    }
    
    Window::~Window()
    {
      glfwTerminate();
    }
        
    void Window::init()
    {
      if(!glfwInit())
	{
	  std::cout << "Failed to initialize GLFW" << std::endl;
	  exit(0);
	}

      // USING THE CORRECT OPENGL
      // minimum version: OpenGL 3.3
      // The Forward Compatibility makes MAC OS X use 4.1
      // all good
      
      //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
      //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
      //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
      //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
      
      // PLEASE MAC OS X BE HAPPY.

      
      this->window = glfwCreateWindow(width, height, this->name, NULL, NULL);
      if(!this->window)
	{
	  glfwTerminate();
	  std::cout << "Failed to create glfw window" << std::endl;
	  exit(0);
	}

      glfwMakeContextCurrent(this->window);
      glfwSetWindowSizeCallback(this->window, windowResize);
    }

    void Window::clear() const
    {
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    
    bool Window::close() const
    {
      return glfwWindowShouldClose(this->window);
    }
    
    void Window::update() const
    {
      glfwPollEvents();
      glfwSwapBuffers(this->window);
    }

    void windowResize(GLFWwindow * window, int width, int height)
    {
      glViewport(0, 0, width, height);
    }
  }
}
