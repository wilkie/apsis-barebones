#include "iso-tasty/primitives/vertex_shader.h"

#ifdef _WIN32
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

// Include GLEW
#include <GL/glew.h>

#ifndef NO_GL
  #ifdef _WIN32
  #include <windows.h>
  #endif

  #include <GL/gl.h>
  #include <GL/glu.h>
#endif

IsoTasty::Primitives::VertexShader::VertexShader(const char* source) {
  this->_vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(this->_vertexShader, 1, &source, NULL);
  glCompileShader(this->_vertexShader );
}

IsoTasty::Primitives::VertexShader IsoTasty::Primitives::VertexShader::fromFile(const char* path) {
  FILE* f = fopen(path, "r");
  if (f == NULL) {
    throw "Shader not found.";
  }

  fseek(f, 0, SEEK_END);
  unsigned long file_length = ftell(f);
  fseek(f, 0, SEEK_SET);

  if (file_length == 0) {
    return VertexShader("");
  }

  char* source = new char[file_length + 1];
  if (source == NULL) {
    throw "Memory depleted";
  }

  for (unsigned int i = 0; !feof(f); i++) {
    source[i] = getc(f);
  }

  source[file_length] = 0;

  fclose(f);

  VertexShader& ret = VertexShader(source);
  delete [] source;
  return ret;
}

IsoTasty::Primitives::VertexShader::~VertexShader() {
  glDeleteShader(this->_vertexShader);
}

unsigned int IsoTasty::Primitives::VertexShader::identifer() const {
  return this->_vertexShader;
}