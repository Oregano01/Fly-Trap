#include <SDL2/SDL.h>
#include <stdio.h>
#include <SDL2/SDL_image.h>

#include "gameWindow.hpp"
#include "player.hpp"

RenderWindow *renderWin = nullptr;
Player *player = nullptr;
//main loop
int main(int argc, char* args[] )
{
    renderWin = new RenderWindow();

    renderWin->init("Fly-Trap", 1280, 720);
    player->Player(renderWin, 120, 120, 100, 100, 200, 125, 100, 255);

    while (renderWin->running())
    {
      player->draw();
      renderWin->event();
      renderWin->update();
      renderWin->render();

    }

  renderWin->clean();

  return 0;
}
