#pragma once

#include "gameWindow.hpp"

class Player : public RenderWindow
{
public:

  Player();
  ~Player();
  void draw();
private:
  int _x = 1000 , _y = 300 , _w = 200 , _h = 200 ;
  int _r,_g,_b,_a;

};
