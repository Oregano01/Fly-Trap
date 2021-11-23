#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "gameWindow.hpp"

RenderWindow::RenderWindow() {}
RenderWindow::~RenderWindow() {}

//Player texture
SDL_Texture* PlayerFlyTexture;
//Rectangle to contain our Player texture
SDL_Rect* srcRect, destRect;

void RenderWindow::init(const char* title, int win_Width, int win_Height)
{
  if( SDL_Init( SDL_INIT_EVERYTHING ) == 0 )
  {
      window = SDL_CreateWindow( "Fly-Trap", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, win_Width , win_Height , 0 );
      screenSurface = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);

      // Creating and rendering out player texture
      SDL_Surface* temporarySurface = IMG_Load("graphics/fly.png");
      PlayerFlyTexture = SDL_CreateTextureFromSurface(screenSurface, temporarySurface);
      SDL_FreeSurface(temporarySurface);


      gameRunning = true;
    }
    else
    {
      gameRunning = false;

    }
  }

//Function taking all events
void RenderWindow::event()
{
  SDL_Event event;

  if (SDL_PollEvent(&event)) {
    switch (event.type) {
        case SDL_QUIT:
            gameRunning = false;
            break;

//case where we click ESC and our gamewindow will close
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
    SDL_SetRenderDrawColor(screenSurface, 120, 150, 125, 255);
    SDL_RenderClear(screenSurface);
    SDL_RenderCopy(screenSurface, PlayerFlyTexture, srcRect, &destRect);

    //rendering square on screen
    SDL_Rect rect;

    rect.w = 120;
    rect.h = 120;
    rect.x = win_Width / 2;
    rect.y = win_Height / 2;

    SDL_SetRenderDrawColor(screenSurface, 200, 150, 125, 255);
    SDL_RenderFillRect(screenSurface, &rect);

    SDL_RenderPresent(screenSurface);
}

void RenderWindow::update()
{

  destRect.h = 200;
  destRect.w = 200;

}

void RenderWindow::clean()
{
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(screenSurface);
  SDL_Quit();
}
