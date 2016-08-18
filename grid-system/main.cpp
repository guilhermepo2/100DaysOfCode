#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define HORIZONTAL_TILES 10
#define VERTICAL_TILES 10


// Including GLEW - Always do it before gl.h and glfw.h
#include <GL/glew.h>
// Including GLFW
#include <GLFW/glfw3.h>
// Including OpenGL Mathematics
#include <glm/glm.hpp>

void draw_square_on_tiles();

int main()
{
  if( !glfwInit() )
    {
      fprintf(stderr, "Failed to initialize GLFW.\n");
      return -1;
    }

  // Open a window and create the OpenGL context
  GLFWwindow * window;
  window = glfwCreateWindow(1024, 768, "Ebin grid System", NULL, NULL);
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

  glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

  do {
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    // Draw Something here!
    draw_square_on_tiles();
    
    glfwSwapBuffers(window);
    glfwPollEvents();
    
  } while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
	   glfwWindowShouldClose(window) == 0 );

  glfwTerminate();
  return 0;
}

void draw_square_on_tiles()
{
  float horizontal_pass = (1.0f / HORIZONTAL_TILES);
  float vertical_pass = (1.0f / VERTICAL_TILES);
  
  for(float i = -1.0f; i < 1.0f; i += vertical_pass)
    {
      for(float j = -1.0f; j < 1.0f; j += horizontal_pass)
	{
	  glColor3f(1.0f, 1.0f, 1.0f);
	  glBegin(GL_QUADS);
	  glVertex3f(j, i, 0.0f);
	  glVertex3f(j+horizontal_pass, i, 0.0f);
	  glVertex3f((j+horizontal_pass),
	  	     i+vertical_pass, 0.0f);
	  glVertex3f(j, i+vertical_pass, 0.0f);
	  glEnd();

	  j += horizontal_pass;
	  
	  glColor3f(1.0f, 0.0f, 0.0f);
	  glBegin(GL_QUADS);
	  glVertex3f(j, i, 0.0f);
	  glVertex3f((j+horizontal_pass), i, 0.0f);
	  glVertex3f((j+horizontal_pass),
	  	     i+vertical_pass, 0.0f);
	  glVertex3f(j, i+vertical_pass, 0.0f);
	  glEnd();
	  
	  glEnd();
	}
    }
}
