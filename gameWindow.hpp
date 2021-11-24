#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

//class rendering our game window
class RenderWindow
{
public:

    RenderWindow();
    ~RenderWindow();

    void init(const char* title, int win_Width, int win_Height);
    void update();
    void render();
    void clean();
    void event();

    bool running() {return gameRunning;}

private:
    SDL_Window* window = NULL;
    bool gameRunning;

protected:
    SDL_Renderer* screenSurface = NULL;

};
