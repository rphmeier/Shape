#include <cassert>
#include <glbinding/Binding.h>
#include "window.h"

using Game::GameWindow;

GameWindow::GameWindow() {
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    
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
    
    // load GL function pointers
    glbinding::Binding::initialize();
}

GameWindow::~GameWindow() {
    SDL_GL_DeleteContext(gl);
    SDL_DestroyWindow(window);
}

void GameWindow::swap_buffers() {
    SDL_GL_SwapWindow(window);
}