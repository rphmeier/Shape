#include "SDL_video.h"

namespace Game {
    
    // A GameWindow manages a raw SDL2 window and OpenGL context.
    class GameWindow {
        public:
        // Creates a new GameWindow with an OpenGL context.
        // SDL must already be initialized with video.
        GameWindow();
        GameWindow(const GameWindow&) = delete;
        ~GameWindow();
        
        
        private:
        SDL_Window* window;
        SDL_GLContext gl;
    };
}