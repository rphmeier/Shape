#pragma once

#include <memory>
#include <vector>

#include <glbinding/gl/gl.h>

namespace Game {
namespace Graphics {

/// Compile a shader program.
gl::GLuint compile_shader(const char* vertex_src, const char* fragment_src);

// A texture is an image.
class Texture {
};

// A rectangular view into a texture.
class TextureView {
    TextureView(Texture& tex, unsigned int x, unsigned int y,
                int width, int height) :
                tex(tex), x(x), y(y), width(width), height(height) {}
    public:
    Texture& texture() const { return tex; }
    
    private:
    Texture& tex;
    unsigned int x, y;
    int width, height;
};

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