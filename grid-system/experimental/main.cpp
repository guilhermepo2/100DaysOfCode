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
void draw_square();
FileHandler map("maps/astar.tmap");

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
  glewExperimental = true;
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
	    case 'G':
	      glColor3ub(143, 209, 101);
	      break;
	    case 'S':
	      glColor3ub(199, 190, 155);
	      break;
	    case 'F':
	      glColor3ub(1, 176, 94);
	      break;
	    case 'M':
	      glColor3ub(149, 137, 91);
	      break;
	    case 'W':
	      glColor3ub(79, 143, 208);
	      break;
	    default:
	      glColor3ub(0, 0, 0);
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
