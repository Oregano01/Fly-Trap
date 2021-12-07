#include "player.hpp"
#include <iostream>

Player::Player() {}
Player::~Player() {}

SDL_Texture* PlayerFlyTexture;

void Player::draw()
{

  SDL_Rect rect;

  rect.w = _w;
  rect.h = _h;
  rect.x = _x;
  rect.y = _y;

  auto temporarySurface = IMG_Load("graphics/fly.png");
  PlayerFlyTexture = SDL_CreateTextureFromSurface(screenSurface, temporarySurface);

  SDL_FreeSurface(temporarySurface);
  SDL_RenderCopy(screenSurface, PlayerFlyTexture, nullptr, &rect);

  SDL_RenderPresent(screenSurface);
}
