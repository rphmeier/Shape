#pragma once

namespace Game { 
namespace Graphics {

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
    
}
}