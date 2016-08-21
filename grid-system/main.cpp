#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "fileHandler/fileHandler.hpp"

#define HORIZONTAL_TILES 10
#define VERTICAL_TILES 10

// Including GLEW - Always do it before gl.h and glfw.h
#include <GL/glew.h>
// Including GLFW
#include <GLFW/glfw3.h>
// Including OpenGL Mathematics
#include <glm/glm.hpp>

void draw_tiles();
FileHandler map("maps/background_sample04.tmap");

int main()
{
  
  if( !glfwInit() )
    {
      fprintf(stderr, "Failed to initialize GLFW.\n");
      return -1;
    }

  // Open a window and create the OpenGL context
  GLFWwindow * window;
  window = glfwCreateWindow(1024, 768, "LE EBIN GRID SYSTEM", NULL, NULL);
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
    draw_tiles();
    
    glfwSwapBuffers(window);
    glfwPollEvents();
    
  } while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
	   glfwWindowShouldClose(window) == 0 );

  glfwTerminate();
  return 0;
}


void draw_tiles()
{
  float pass = (2.0f / map.getDimension());
  float halfPass = pass/2.0f;

  #if DEBUG
  std::cout << "Pass: " << pass << std::endl;
  std::cout << "Half Pass: " << halfPass << std::endl;
  #endif
  
  float y = (1.0f - halfPass);
  for(int i = 0; i < map.getDimension(); i++)
    {
      float x = (-1.0f + halfPass);
      for(int j = 0; j < map.getDimension(); j++)
	{
	  switch(map.getMatrixPosition(i,j))
	    {
	    case 'B':
	      glColor3f(0.0f, 0.0f, 1.0f);
	      break;
	    case 'R':
	      glColor3f(1.0f, 0.0f, 0.0f);
	      break;
	    case 'G':
	      glColor3f(0.0f, 1.0f, 0.0f);
	      break;
	    case 'X':
	      glColor3f(0.5f, 0.5f, 0.5f);
	      break;
	    }

	  glBegin(GL_QUADS);
	  glVertex3f(x-halfPass,y-halfPass,0.0f);
	  glVertex3f(x-halfPass,y+halfPass,0.0f);
	  glVertex3f(x+halfPass,y+halfPass,0.0f);
	  glVertex3f(x+halfPass,y-halfPass,0.0f);
	  glEnd();

	  x += pass;
	}
      y -= pass;
    }
}
