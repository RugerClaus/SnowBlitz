#include "../../include/display/Screen.h"

#include <stdexcept>

Screen::Screen(const std::string& title, int width, int height)
    : width(width), height(height) {
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              width, height, SDL_WINDOW_RESIZABLE);
    if (!window) throw std::runtime_error("Failed to create window");

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) throw std::runtime_error("Failed to create renderer");
}

Screen::~Screen() {
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);
}

void Screen::fill(SDL_Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(renderer);
}

void Screen::update() {
    SDL_RenderPresent(renderer);
}

void Screen::blit(SDL_Texture* texture, SDL_Rect* srcRect = nullptr, SDL_Rect* destRect = nullptr)
{
    return;
}

void Screen::setTitle(const std::string& title) {
    SDL_SetWindowTitle(window, title.c_str());
}

void Screen::setIcon(SDL_Surface* icon) {
    SDL_SetWindowIcon(window, icon);
}

SDL_Renderer* Screen::getRenderer() const { return renderer; }
SDL_Window* Screen::getWindow() const { return window; }

void Screen::getSize(int& w, int& h) const {
    SDL_GetWindowSize(window, &w, &h);
}
