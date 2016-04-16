#include "SDL.h"
#include "SDL_video.h"

int main(int argc, char** argv) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS) != 0) {
        return 1;
    }
    
    SDL_Window* window = SDL_CreateWindow(
        "shape",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        1024,
        768,
        SDL_WINDOW_OPENGL
    );
    
    if (window == NULL) {
        return 1;
    }
    
    SDL_Delay(1000);
    
    SDL_DestroyWindow(window);
     
    SDL_Quit();
    return 0;
}