#include <algorithm>
#include <iostream>

#include "sprite.h"

using namespace Game::Graphics;

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