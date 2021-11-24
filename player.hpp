#pragma once

#include "gameWindow.hpp"

class Player : public RenderWindow {
public:
  Player(const RenderWindow &window, int w, int h, int x, int y, int r, int g, int b, int a);

  void const draw();

private:
  int _w, _h;
  int _x, _y;
  int _r, _g, _b, _a;

};
