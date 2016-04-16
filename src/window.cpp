#include "window.h"
#include <cassert>

Game::GameWindow::GameWindow() {
    window = SDL_CreateWindow(
        "shape",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        1024,
        768,
        SDL_WINDOW_OPENGL
    );
    
    assert(window != NULL);
    
    gl = SDL_GL_CreateContext(window);
}

Game::GameWindow::~GameWindow() {
    SDL_GL_DeleteContext(gl); 
    SDL_DestroyWindow(window);
}