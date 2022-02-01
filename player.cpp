#include <iostream>
#include "player.hpp"
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

//selecting actual dividing height and width of our sprites by given values
  rect.w /= frameX;
  rect.h /= frameY;

//selecting exact frame
  frameWidth = position.w = rect.w;
  frameHeight = position.h = rect.h;

  Active = false;

}


Player::~Player()
{
  SDL_DestroyTexture(PlayerFlyTexture);
}


void Player::update(float delta, const Uint8 *key)
{
  Active = true;

  // if sequence where we are chosing proper animation frame
   if(key[SDL_SCANCODE_W])
   {
     position.y -= moveSpeed * delta;
     rect.y = frameHeight * 3;
   }
   else if(key[SDL_SCANCODE_S])
   {
     position.y += moveSpeed * delta;
     rect.y = 0;
   }
   else if(key[SDL_SCANCODE_A])
   {
     position.x -= moveSpeed * delta;
     rect.y = frameHeight;
   }
   else if(key[SDL_SCANCODE_D])
   {
     position.x += moveSpeed * delta;
     rect.y = frameHeight * 2;
   }
   else
   {
     Active = false;
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


  SDL_RenderCopy(RenderWindow::screenSurface, PlayerFlyTexture, &rect, &position);

}
