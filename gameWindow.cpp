#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "player.hpp"
#include "gameWindow.hpp"

RenderWindow::RenderWindow() {}
RenderWindow::~RenderWindow() {}

Player* player;

SDL_Renderer* RenderWindow::screenSurface = nullptr;

float currentTime;
float prevTime;
float delta;

void RenderWindow::init(const char* title, int win_Width, int win_Height)
{
  if( SDL_Init( SDL_INIT_EVERYTHING ) == 0 )
  {
      window = SDL_CreateWindow( "Fly-Trap", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, win_Width , win_Height , SDL_WINDOW_RESIZABLE );
      screenSurface = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);

      gameRunning = true;
    }
    else
    {
      gameRunning = false;

    }
    player = new Player("graphics/player.png", 100, 100, 3, 4);

  }

//
void RenderWindow::event()
{
  SDL_Event event;
  if (SDL_PollEvent(&event)) {
    switch (event.type) {
        case SDL_QUIT:
            gameRunning = false;
        break;

    case SDL_KEYDOWN:
      switch (event.key.keysym.sym) {
        case SDLK_ESCAPE:
            gameRunning = false;
            break;

      }
      default:
          break;

    }
  }
}

void RenderWindow::render()
{
    SDL_RenderClear(screenSurface);
    player->render();

    SDL_RenderPresent(screenSurface);
}

void RenderWindow::update()
{
  prevTime = currentTime;
  currentTime = SDL_GetTicks();
  delta = (currentTime - prevTime) / 1000;

  player -> update(delta);
}

void RenderWindow::clean()
{
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(screenSurface);
  IMG_Quit();
  SDL_Quit();
}
