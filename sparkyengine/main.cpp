#include "graphics/window.h"

int main()
{
  sparky::graphics::Window window("Sparky Engine", 800, 600);
  glClearColor(0.5f, 0.5f, 0.85f, 1.0f);
  std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
  std::cout << "OpenGL Renderer: " << glGetString(GL_RENDERER) << std::endl;
  std::cout << "Shading Language: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

  GLuint vao;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);
  
  while(!window.close())
    {
      window.clear();

      #if 0
      glBegin(GL_TRIANGLES);
      glVertex2f(-0.5f, -0.5f);
      glVertex2f(0.0f, 0.5f);
      glVertex2f(0.5f, -0.5f);
      glEnd();
      #endif
      
      glDrawArrays(GL_ARRAY_BUFFER, 0, 0);
      
      window.update();
    }
  
  return 0;
}
