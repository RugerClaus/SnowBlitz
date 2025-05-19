#pragma once
#ifndef SCREEN_H
#define SCREEN_H

#include <SDL2/SDL.h>
#include <string>

class Screen {
public:
    Screen(const std::string& title, int width, int height);
    ~Screen();

    void fill(SDL_Color color);
    void update();
    void blit(SDL_Texture* texture, SDL_Rect* srcRect = nullptr, SDL_Rect* destRect = nullptr);
    void setTitle(const std::string& title);
    void setIcon(SDL_Surface* icon);

    SDL_Renderer* getRenderer() const;
    SDL_Window* getWindow() const;
    void getSize(int& w, int& h) const;

private:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    int width, height;
};

#endif