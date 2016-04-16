#pragma once

#include <memory>
#include <vector>

#include <glbinding/gl/gl.h>

#include "texture.h"

namespace Game { 
namespace Graphics {

class SpriteBatch;
  
class Sprite {
    friend class SpriteBatch;
    public:
    Sprite(TextureView tex, unsigned int depth) : tex(tex), depth(depth) {}
    
    private:
    TextureView tex;
    unsigned int depth;
};

class SpriteBatch {
    struct BatchEntry {
        BatchEntry(Sprite sprite, unsigned int x, unsigned int y) : sprite(sprite), x(x), y(y) {}
        
        public:
        Sprite sprite;
        unsigned int x, y;
    };
    
    public:
    SpriteBatch();
    
    void begin();
    void draw(Sprite, unsigned int, unsigned int);
    void end();
    
    private:
    std::vector<BatchEntry> sprites;
    gl::GLuint shader_handle;
};
    
}
}