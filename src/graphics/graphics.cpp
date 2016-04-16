#include <cassert>
#include "graphics.h"

using namespace gl;

GLuint compile_shader(const char* vertex_src, const char* fragment_src) {
    GLuint vertex_id = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragment_id = glCreateShader(GL_FRAGMENT_SHADER);
    
    glShaderSource(vertex_id, 1, &vertex_src, NULL);
    glCompileShader(vertex_id);
    glShaderSource(fragment_id, 1, &fragment_src, NULL);
    glCompileShader(fragment_id);
    
    GLuint program_id = glCreateProgram();
    glAttachShader(program_id, vertex_id);
    glAttachShader(program_id, fragment_id);
    glLinkProgram(program_id);
    
    glDetachShader(program_id, vertex_id);
    glDetachShader(program_id, fragment_id);
    
    glDeleteShader(vertex_id);
    glDeleteShader(fragment_id);
    
    return program_id;
}