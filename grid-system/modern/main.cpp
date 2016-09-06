/*
COMPILING:
g++ main.cpp -o main -I/usr/local/include -I/opt/X11/lib -L/usr/local/lib -lglfw3 -framework OpenGL -lglew
*/
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "common/loadShader.hpp"
#include <iostream>

int main()
{ 
  if( !glfwInit() )
    {
      fprintf(stderr, "Failed to initialize GLFW.\n");
      return -1;
    }

  glfwWindowHint (GLFW_SAMPLES, 4);
  glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint (GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint (GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



  GLFWwindow * window;
  window = glfwCreateWindow(1024, 768, "Tutorial 02", NULL, NULL);
  if(window == NULL)
    {
      fprintf(stderr, "Error creating window :(\n");
      glfwTerminate();
      return -1;
    }

  glfwMakeContextCurrent(window);


  // GLEW EXPERIMENTAL ? when it isn't here I get a segmentation fault on the glGenVertexArrays, but if this line here it works just fine...
  /*
    GLEW obtains information on the supported extensions from the graphics driver. Experimental or pre-release drivers, however, might not report every available extension through the standard mechanism, in which case GLEW will report it unsupported. To circumvent this situation, the glewExperimental global switch can be turned on by setting it to  GL_TRUE before calling glewInit(), which ensures that all extensions with valid entry points will be exposed
  */
  glewExperimental = GL_TRUE;
  if( glewInit() != GLEW_OK)
    {
      fprintf(stderr, "Failed to initialize GLEW\n");
      getchar();
      glfwTerminate();
      return -1;
    }


  glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

  glClearColor(0.0f, 0.0f, 0.4f, 0.0f);


  // Creating the VAO (Vertex Array Object)
  GLuint VertexArrayID;
  glGenVertexArrays(1, &VertexArrayID);
  glBindVertexArray(VertexArrayID);

  // We need three 3D points in order to make a triangle, so...
  // An array of 3 vectors which represents 3 vertices
  float x = 0.0f;
  float y = 0.0f;
  float z = 0.0f;
  float l = 0.25f;
  
  static const GLfloat g_vertex_buffer_data[] = {
    x-l, y+l, // P1
    x+l, y+l, // P2
    x-l, y-l, // P3
    
    x+l, y+l, // P2
    x-l, y-l, // P3
    x+l, y-l, // P4
    };
  
  // now we have to give our triangle to OpenGL, so...
  // This will identify the vertex buffer
  GLuint vertexbuffer;
  // Generate 1 buffer, put the result id in vertexbuffer
  glGenBuffers(1, &vertexbuffer);
  // binding the buffer
  glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
  // give our vertices to OpenGL
  glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data,
	       GL_STATIC_DRAW);

  // Create and Compile our GLSL program from the shader
  GLuint programID = LoadShaders("SimpleVertexShader.vertexshader",
				 "SimpleFragmentShader.fragmentshader");


  do {
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    // use our shader
    glUseProgram(programID);

    // Now we can draw our triangle :)
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(
			  0,          //
			  2,          // size
			  GL_FLOAT,   // type
			  GL_FALSE,   // normalized?
			  0,          // stride
			  (void*)0    // array buffer offset
			  );
    // Drawing!
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glDisableVertexAttribArray(0);
    
    glfwSwapBuffers(window);
    glfwPollEvents();
    
  } while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
	   glfwWindowShouldClose(window) == 0 );

  //
  glDeleteBuffers(1, &vertexbuffer);
  glDeleteVertexArrays(1, &VertexArrayID);

  glfwTerminate();
  return 0;
}
