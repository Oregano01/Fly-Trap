#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "player.hpp"
#include "gameWindow.hpp"

RenderWindow::RenderWindow() {}
RenderWindow::~RenderWindow() {}

//Player texture
// SDL_Texture* PlayerFlyTexture;
//Rectangle to contain our Player texture
// SDL_Rect* srcRect, destRect;

void RenderWindow::init(const char* title, int win_Width, int win_Height)
{
  if( SDL_Init( SDL_INIT_EVERYTHING ) == 0 )
  {
      window = SDL_CreateWindow( "Fly-Trap", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, win_Width , win_Height , SDL_WINDOW_RESIZABLE );
      screenSurface = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);

      // Player draw(screenSurface);

      gameRunning = true;
    }
    else
    {
      gameRunning = false;

    }
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
        // case SDLK_f:
        //     SDL_WINDOW_FULLSCREEN;
        //     break;

//moving player
        // case SDLK_LEFT:
        //     _x -= 10;
        //     break;
        // case SDLK_RIGHT:
        //     _x += 10;
        //     break;
        // case SDLK_UP:
        //     _y -= 10;
        //     break;
        // case SDLK_DOWN:
        //     _y += 10;
        //     break;
      }
      default:
          break;

    }
  }
}

void RenderWindow::render()
{
    SDL_SetRenderDrawColor(screenSurface, 120, 150, 125, 255);
    SDL_RenderClear(screenSurface);

    //Rectangle containing our player graphic
    // SDL_Rect rect;
    // //position, width and height
    // rect.w = _w;
    // rect.h = _h;
    // rect.x = _x;
    // rect.y = _y;

    // Creating and rendering out player texture and later
    // auto temporarySurface = IMG_Load("graphics/fly.png");
    // PlayerFlyTexture = SDL_CreateTextureFromSurface(screenSurface, temporarySurface);
    //
    // SDL_FreeSurface(temporarySurface);
    // SDL_RenderCopy(screenSurface, PlayerFlyTexture, nullptr, &rect);
    SDL_RenderPresent(screenSurface);
}

void RenderWindow::update()
{

  // destRect.h = 200;
  // destRect.w = 200;

}

void RenderWindow::clean()
{
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(screenSurface);
  IMG_Quit();
  SDL_Quit();
}
