#include "player.hpp"
#include <iostream>
#include "gameWindow.hpp"


Player::Player(std::string filePath, int x, int y, int frameX, int frameY)
{
  //creating surface for our player texture
  SDL_Surface *screenSurface = IMG_Load(filePath.c_str());
  if (screenSurface == nullptr)
      std::cout <<"Surface Error"<<std::endl;
  else
  {
    //rendering texture
    PlayerFlyTexture = SDL_CreateTextureFromSurface(RenderWindow::screenSurface, screenSurface);

    if (PlayerFlyTexture == nullptr)
        std::cout << "Texture Error" << std::endl;
  }

  SDL_FreeSurface(screenSurface);
//getting total width and height of the texture
  SDL_QueryTexture(PlayerFlyTexture, nullptr, nullptr, &rect.w, &rect.h);

  position.x = x;
  position.y = y;

  textureWidth = rect.w;

//selecting actual sprite
  rect.w /= frameX;
  rect.h /= frameY;

  frameWidth = position.w = rect.w;
  frameHeight = position.h = rect.h;

  Active = false;

  static int playerNumber = 0;
  playerNumber++;

  if (playerNumber ==1)
  {

  }
}


Player::~Player()
{
  SDL_DestroyTexture(PlayerFlyTexture);
}


void Player::update(float delta)
{
  Active = true;
  //drawind and moving our sprites animation
  if(SDL_SCANCODE_W)
  {
    position.y -= moveSpeed * delta;
    rect.y = frameHeight * 3;
  }
  else if (SDL_SCANCODE_S)
  {
    position.y += moveSpeed * delta;
    rect.y = 0;
  }
  else if (SDL_SCANCODE_A)
  {
    position.x -= moveSpeed * delta;
    rect.y = frameHeight;
  }
  else if (SDL_SCANCODE_D)
  {
    position.x += moveSpeed * delta;
    rect.y  = frameHeight * 2;
  }

  if(Active)
  {
    frameCount += delta;

    if(frameCount >= 0.25f)
    {
      frameCount = 0;
      rect.x += frameWidth;

      if (rect.x >= textureWidth)
          rect.x = 0;
    }
  }
  else
  {
    frameCount = 0;
    rect.x = frameWidth;
  }

}

// SDL_Texture* PlayerFlyTexture;

void Player::render()
{



  // SDL_Rect rect;
  //
  // rect.w = _w;
  // rect.h = _h;
  // rect.x = _x;
  // rect.y = _y;
  //
  //
  // auto temporarySurface = IMG_Load("graphics/fly.png");
  // SDL_FreeSurface(temporarySurface);
  SDL_RenderCopy(RenderWindow::screenSurface, PlayerFlyTexture, &rect, &position);

}
