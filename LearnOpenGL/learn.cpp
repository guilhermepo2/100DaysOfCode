#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

// our shaders
const GLchar* vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 position;\n"
    "void main()\n"
    "{\n"
    "gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
    "}\0";
const GLchar* fragmentShaderSource = "#version 330 core\n"
    "out vec4 color;\n"
    "void main()\n"
    "{\n"
    "color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";

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
  glfwWindowHint(GLFW_SAMPLES, 16);     // antialising
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

  // we want to render our triangle
  GLfloat vertices[] = {
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f, 0.5f, 0.0f
  };

  //vertex shader
  GLuint vertexShader;
  vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);
  // checking if succeeded
  GLint success;
  GLchar infoLog[512];
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if(!success)
    {
      glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
      std::cout << "ERROR: " << infoLog << std::endl;
    }
  else std::cout << "vertex shader compiled." << std::endl;

  // fragment shader
  GLuint fragmentShader;
  fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);
    // checking if succeeded
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if(!success)
    {
      glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
      std::cout << "ERROR: " << infoLog << std::endl;
    }
  else std::cout << "fragment shader compiled." << std::endl;

  // shader program
  GLuint shaderProgram;
  shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);

  // checking success
  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if(!success)
    {
      glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
      std::cout << "ERROR: " << infoLog << std::endl;
    }
  else std::cout << "program linked" << std::endl;
  glUseProgram(shaderProgram);

  // after creating the shader program, we dont need the individual shaders anymore
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);


  
  // creating the Vertex Array Object
  GLuint VAO;
  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);

  // creating the vertex buffer to pass data to the GPU
  GLuint VBO;
  glGenBuffers(1, &VBO);
  // now we bind the buffer
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  // now we pass data to the binded buffer
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat),
			(GLvoid*)0);
  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);


  while(!glfwWindowShouldClose(window))
    {
      //check and call events
      glfwPollEvents();
      glfwSetKeyCallback(window, key_callback);

      // render everything here
      // ...
      glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);
      glUseProgram(shaderProgram);
      glBindVertexArray(VAO);
      glDrawArrays(GL_TRIANGLES, 0, 3);
      glBindVertexArray(0);

      
      //swap buffers
      glfwSwapBuffers(window);
    }

  glfwTerminate();
  return 0;
}
