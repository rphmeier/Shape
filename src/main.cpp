#include "SDL.h"
#include "window.h"

int main(int argc, char** argv) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS) != 0) {
        return 1;
    }
    
    Game::GameWindow window;
    
    SDL_Delay(1000);
    SDL_Quit();
    
    return 0;
}