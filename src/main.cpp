#include <SDL.h>
#include <glbinding/gl/gl.h>

#include "window.h"

int main(int argc, char** argv) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS) != 0) {
        return 1;
    }
    
    Game::GameWindow window;
    
    gl::glClearColor(0.0, 0.0, 0.0, 0.0);
    gl::glClear(gl::GL_COLOR_BUFFER_BIT);
    
    window.swap_buffers();
    
    SDL_Delay(1000);
    
    SDL_Quit(); 
    return 0;
}