#include <SDL2/SDL.h>
#include <stdio.h>
#include <SDL2/SDL_image.h>

#include "gameWindow.hpp"
#include "player.hpp"

RenderWindow *renderWin = nullptr;

//main loop
int main(int argc, char* args[] )
{
    renderWin = new RenderWindow();

    renderWin->init("Fly-Trap", 800, 680);

    while (renderWin->running())
    {

      renderWin->event();
      renderWin->update();
      renderWin->render();
    }

  renderWin->clean();

  return 0;
}
