#pragma once
#ifndef APP_H
#define APP_H

#include <SDL2/SDL.h>
#include <iostream>
#include <string>

#include "../display/Screen.h"

class App
{
public:
    App(const std::string& version);   // Constructor declaration
    ~App();                          // Destructor declaration

    std::string version;

    void run();

private:
    Screen* screen;
    bool running;
};

#endif
