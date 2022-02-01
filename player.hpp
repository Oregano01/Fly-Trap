#pragma once

#include "gameWindow.hpp"

class Player
{
public:

  Player(std::string filePath, int x, int y, int frameX, int frameY);
  ~Player();

  void update(float delta, const Uint8* key);
  void render();
private:
  SDL_Rect rect;
  SDL_Texture* PlayerFlyTexture;

  float moveSpeed = 100;
  float frameCount;

  bool Active;

  int frameWidth, frameHeight;
  int textureWidth;

  SDL_Rect position;

};
