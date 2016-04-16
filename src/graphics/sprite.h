#include <memory>
#include <vector>

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
        
        Sprite sprite;
        unsigned int x, y;
    };
    
    public:
    void begin();
    void draw(Sprite, unsigned int, unsigned int);
    void end();
    
    private:
    std::vector<BatchEntry> sprites;
};
    
}
}