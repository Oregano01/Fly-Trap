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

    static SDL_Renderer *screenSurface;

private:
    SDL_Window* window = nullptr;
    bool gameRunning;
    // int _x = 1000 , _y = 300 , _w = 200 , _h = 200 ;
protected:

};
