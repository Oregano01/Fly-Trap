#pragma once

#include "gameWindow.hpp"

class Player : public RenderWindow
{
public:

  Player(SDL_Renderer *textureRender, std::string filePath, int x, int y, int frameX, int frameY);
  ~Player();

  void update(float delta);
  void draw(SDL_Renderer *textureRender);
private:
  SDL_Rect rect;
  SDL_Texture *PlayerFlyTexture;

  float moveSpeed;
  float frameCount;

  bool Active;

  int _x = 1000 , _y = 300 , _w = 200 , _h = 200 ;
  int frameWidth, frameHeight;
  int textureWidth;

  SDL_Rect position;

};
