#include <SDL.h>
#include <SDL_keyboard.h>
#include <SDL_keycode.h>

#include "window.h"
#include "graphics.h"

// handles game events.
// returns true if quit requested.
bool handle_events() {
    bool needs_quit = false;
    
    SDL_PumpEvents();
    auto keyboard = SDL_GetKeyboardState(NULL);
    if (keyboard[SDL_SCANCODE_ESCAPE] || SDL_QuitRequested()) { needs_quit = true; }
    
    return needs_quit;
}

int main(int argc, char** argv) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS) != 0) {
        return 1;
    }
    
    Game::GameWindow window;
    
    bool running = true;
    while (running) {
        gl::glClearColor(0.0, 0.0, 0.0, 0.0);
        gl::glClear(gl::GL_COLOR_BUFFER_BIT);
        
        running = !handle_events();
        
        window.swap_buffers();
    }
    
    SDL_Quit(); 
    return 0;
}