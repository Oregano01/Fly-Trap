#pragma once

#include "gameWindow.hpp"

class Player : public RenderWindow
{
public:

  Player(const RenderWindow &screenSurface, int w, int h, int x, int y, int r, int g, int b, int a);

  void draw();
private:
  int _w,_h;
  int _x,_y;
  int _r,_g,_b,_a;
};
