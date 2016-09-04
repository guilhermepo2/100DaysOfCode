//#pragma once // incluida no Visual C++

#ifndef WINDOW_HEADER
#define WINDOW_HEADER

#include <GLFW/glfw3.h>
#include <iostream>

namespace sparky
{
  namespace graphics
  {
    class Window
    {
    private:
      const char * name;
      int width, height;
      GLFWwindow * window;
      
    public:
      Window(const char * name, int width, int height);
      ~Window();
      bool close() const;
      void update() const;
      void clear() const;

      inline int getWidth() const { return this->width; }
      inline int getHeight() const { return this->height; }

    private:
      void init();
    };
  }
}

#endif
