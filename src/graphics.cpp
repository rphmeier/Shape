#include <algorithm>
#include <cassert>
#include <iostream>

#include "graphics.h"

using namespace gl;
using namespace Game::Graphics;

GLuint Game::Graphics::compile_shader(const char* vertex_src, const char* fragment_src) {
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

const char* vertex_src = 
    "#version 330"
    "in vec3 pos;"
    "in vec2 vert_tex_coord;"
    "out vec2 tex_coord;"
    
    "void main() {"
    "    tex_coord = vert_tex_coord;"
    "    gl_Position = vec4(pos, 1.0);"
    "}";
    
const char* frag_src = 
    "#version 330"
    "uniform Sampler2D tex;"
    "uniform vec2 tex_coord;"
    
    "void main() {"
    "    gl_Color = texture(tex, tex_coord);"
    "}";
    

SpriteBatch::SpriteBatch() {
    shader_handle = Game::Graphics::compile_shader(vertex_src, frag_src);
}

void SpriteBatch::begin() {
    sprites.clear();
}

void SpriteBatch::draw(Sprite sprite, unsigned int x, unsigned int y) {
    BatchEntry entry(sprite, x, y);
    
    sprites.push_back(entry);
}

void SpriteBatch::end() {
    // sort the sprites by z-order and texture.
    
    // start the shader.
    for (auto i = sprites.begin(); i < sprites.end(); i++) {
        // if last texture different than previous, switch the shader uniform.
        // update the shader attributes.
        std::cout << "drawing sprite at (" << i->x << ", " << i->y << ").";
    }
    
    // end the shader
}