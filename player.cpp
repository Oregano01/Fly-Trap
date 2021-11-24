#include "player.hpp"

Player::Player(const RenderWindow &screenSurface,int w, int h, int x, int y, int r, int g, int b, int a):
RenderWindow(screenSurface), _w(w), _h(h), _x(x), _y(y), _r(r), _g(g), _b(b), _a(a)
{

}
Player::~Player() {}

void Player::draw()
{
  SDL_Rect rect;
  rect.w = _w;
  rect.h = _h;
  rect.x = _x;
  rect.y = _y;

  SDL_SetRenderDrawColor(screenSurface, 200, 100, 125, 255);
  SDL_RenderFillRect(screenSurface, &rect);
}
