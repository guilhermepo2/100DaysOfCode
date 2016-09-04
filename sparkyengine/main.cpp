#include "graphics/window.h"

int main()
{
  sparky::graphics::Window window("Sparky Engine", 800, 600);
  glClearColor(0.5f, 0.5f, 0.85f, 1.0f);
  std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
  std::cout << "OpenGL Renderer: " << glGetString(GL_RENDERER) << std::endl;
  std::cout << "Shading Language: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
					
  while(!window.close())
    {
      window.clear();

      glBegin(GL_TRIANGLES);
      glVertex2f(-0.5f, -0.5f);
      glVertex2f(0.0f, 0.5f);
      glVertex2f(0.5f, -0.5f);
      glEnd();
      
      
      window.update();
    }
  
  return 0;
}
