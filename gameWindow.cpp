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
      window = SDL_CreateWindow( "Fly-Trap", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, win_Width , win_Height , SDL_WINDOW_SHOWN );
      screenSurface = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);
      SDL_SetRenderDrawColor(screenSurface, 120, 150, 125, 255);
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

//
void RenderWindow::event()
{
  SDL_Event event;
  SDL_PollEvent(&event);
  switch (event.type) {
      case SDL_QUIT:
          gameRunning = false;
          break;
      default:
          break;
  }
}
  // if ( SDL_Init(IMG_INIT_PNG ) < 0 )
  // {
  //   printf("SDL_IMAGE coult not initialize!!!! SDL_Error: %s\n", SDL_GetError() );
  // }
//}

//function rendering our game window
// RenderWindow::RenderWindow(const char* title, int win_Width, int win_Height)
// {
//   window = SDL_CreateWindow( "Fly-Trap", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, win_Width , win_Height , SDL_WINDOW_SHOWN );
//   if( window == NULL)
//   {
//     printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
//   }
//   else
//   {
//     screenSurface = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
//
//     SDL_SetRenderDrawColor(screenSurface, 120, 150, 125, 255);
//   }
//
//   //Creating and rendering out player texture
//   SDL_Surface* temporarySurface = IMG_Load("graphics/fly.png");
//   PlayerFlyTexture = SDL_CreateTextureFromSurface(screenSurface, temporarySurface);
//   SDL_FreeSurface(temporarySurface);
//   SDL_RenderClear(screenSurface);
//   SDL_RenderCopy(screenSurface, PlayerFlyTexture, srcRect, &destRect);
//   SDL_RenderPresent(screenSurface);
// }

void RenderWindow::render()
{
    SDL_RenderClear(screenSurface);
    SDL_RenderCopy(screenSurface, PlayerFlyTexture, srcRect, &destRect);
    SDL_RenderPresent(screenSurface);
}

void RenderWindow::update()
{

  destRect.h = 300;
  destRect.w = 300;

}

void RenderWindow::clean()
{
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(screenSurface);
  SDL_Quit();
}
