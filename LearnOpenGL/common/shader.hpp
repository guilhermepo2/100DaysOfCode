#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GLFW/glfw3.h>

class Shader
{
public:
  GLuint program;
  Shader(const GLchar * vertexSourcePath, const GLchar * fragmentSourcePath);
  void Use();
};

Shader::Shader(const GLchar * vertexSourcePath, const GLchar * fragmentSourcePath)
{
  // 1 - retrieve source code from filepath
  std::string vertexCode;
  std::string fragmentCode;
  std::ifstream vShaderFile;
  std::ifstream fShaderFile;
  vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  try
    {
      vShaderFile.open(vertexSourcePath);
      fShaderFile.open(fragmentSourcePath);
      std::stringstream vShaderStream, fShaderStream;

      //read file buffer into stream
      vShaderStream << vShaderFile.rdbuf();
      fShaderStream << fShaderFile.rdbuf();
      // close file handlers
      vShaderFile.close();
      fShaderFile.close();
      // convert stream into glchar
      vertexCode = vShaderStream.str();
      fragmentCode = fShaderStream.str();
    } catch(std::ifstream::failure e)
    {
      std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ" << std::endl;
    }

  const GLchar * vShaderCode = vertexCode.c_str();
  const GLchar * fShaderCode = fragmentCode.c_str();

  // 2 - Compile Shader
  GLuint vertex, fragment;
  GLint success;
  GLchar infolog[512];

  // vertex shader
  vertex = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex, 1, &vShaderCode, NULL);
  glCompileShader(vertex);
  // print compile errors if any
  glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
  if(!success)
    {
      glGetShaderInfoLog(vertex, 512, NULL, infolog);
       std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infolog
       << std::endl;
    }

  // fragment shader
  fragment = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment, 1, &fShaderCode, NULL);
  glCompileShader(fragment);
  // print compile error if any
  glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
  if(!success)
    {
      glGetShaderInfoLog(fragment, 512, NULL, infolog);
       std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infolog
       << std::endl;
    }

  // shader Program
  this->program = glCreateProgram();
  glAttachShader(this->program, vertex);
  glAttachShader(this->program, fragment);
  glLinkProgram(this->program);

  glGetShaderiv(this->program, GL_LINK_STATUS, &success);
  if(!success)
    {
      glGetProgramInfoLog(this->program, 512, NULL, infolog);
      std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infolog << std::endl;
    }

  // delete shader

  glDeleteShader(vertex);
  glDeleteShader(fragment);
}

void Shader::Use() { glUseProgram(this->program); }

#endif
