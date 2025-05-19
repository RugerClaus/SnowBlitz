#include "../../include/program/App.h"

App::App(const std::string& version) : version(version) {
    SDL_Init(SDL_INIT_VIDEO); // (and SDL_INIT_AUDIO if needed)

    screen = new Screen("Snow Blitz - v" + version, 1200, 800);
    screen->setTitle("Snow Blitz - " + version);

    // Example: Fill with black at start
    screen->fill({0, 0, 0, 255});
    screen->update();
}

App::~App() {
    delete screen;
    SDL_Quit();
}

void App::run() {
    bool running = true;
    SDL_Event e;

    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = false;
            }
        }

        screen->fill({0, 0, 0, 255}); // Clear
        // ... Draw more stuff here ...
        screen->update(); // Present

        SDL_Delay(16); // ~60 FPS
    }
}
