#include <SDL2/SDL.h>
#include <stdio.h>
#include <SDL2/SDL_image.h>

#include "gameWindow.hpp"
#include "player.hpp"

RenderWindow *renderWin = nullptr;
// Player *player = nullptr;

float currentTime;
float prevTime;
float delta;
//main loop
int main(int argc, char* args[] )
{
    SDL_Window* window = nullptr;
    SDL_Renderer* textureRender = nullptr;

    window = SDL_CreateWindow( "Fly-Trap", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280 , 720 , SDL_WINDOW_RESIZABLE );
    textureRender = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);

    // player = new Player(SDL_Renderer *textureRender, std::string filePath, int x, int y, int frameX, int frameY);
    renderWin = new RenderWindow();

    // renderWin->init("Fly-Trap", 1280 , 720);

    Player player(textureRender, "graphics/fly.png", 0, 0, 1, 1);
    // player->init();

    while (renderWin->running())
    {
      prevTime = currentTime;
      currentTime = SDL_GetTicks();
      delta = (currentTime - prevTime) / 1000;

      player.draw(textureRender);

      renderWin->event();
      renderWin->update();
      renderWin->render();
    }

  renderWin->clean();

  return 0;
}
