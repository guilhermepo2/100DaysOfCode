/*

COMPILING:

g++ main.cpp -o main -I/usr/local/include -I/opt/X11/lib -L/usr/local/lib -lglfw3 -framework OpenGL -lglew

*/

// Lessons about Modern OpenGL (OpenGL 3 and 4)
// Standard Headers...
#include <stdio.h>
#include <stdlib.h>

// Including GLEW - Always do it before gl.h and glfw.h
#include <GL/glew.h>
// Including GLFW
#include <GLFW/glfw3.h>
// Including OpenGL Mathematics
#include <glm/glm.hpp>

int main()
{
  // Initialising GLFW
  if( !glfwInit() )
    {
      fprintf(stderr, "Failed to initialize GLFW.\n");
      return -1;
    }

  // Creating the OpenGL Window
  // 4x antialising
  glfwWindowHint (GLFW_SAMPLES, 4);
  // OpenGL 3.3
  glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR, 3);
  // Make MacOS happy :)
  glfwWindowHint (GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  // Not use the old OpenGL!
  glfwWindowHint (GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Open a window and create the OpenGL context
  GLFWwindow * window;
  window = glfwCreateWindow(1024, 768, "Tutorial 01", NULL, NULL);
  if(window == NULL)
    {
      fprintf(stderr, "Error creating window :(\n");
      glfwTerminate();
      return -1;
    }

  // Making the Context
  glfwMakeContextCurrent(window);

  // Initializing GLEW
  if( glewInit() != GLEW_OK)
    {
      fprintf(stderr, "Failed to initialize GLEW\n");
      getchar();
      glfwTerminate();
      return -1;
    }

  // Ensure that we can capture the escape key being pressed
  glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

  // Dark Blue Background
  glClearColor(0.0f, 0.0f, 0.4f, 0.0f);


  do {
    // clearing the screen
    glClear( GL_COLOR_BUFFER_BIT );

    // Draw Something here!
    
    // Swapping Buffers
    glfwSwapBuffers(window);
    glfwPollEvents();
    
  } while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
	   glfwWindowShouldClose(window) == 0 );

  // Finish it, close OpenGL
  glfwTerminate();
  return 0;
}
