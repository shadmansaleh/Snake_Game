#ifndef SNAKE_HPP_DEFINED
#define SNAKE_HPP_DEFINED

#include "SnakeBody.hpp"
#include "Utils.hpp"
#include <vector>

class Snake {
private:
  std::vector<SnakeBody> body;
  double dt;

public:
  Snake(int snake0x, int snake0y);

  void draw(sf::RenderWindow &);
  void tick(double dt);
  void move(Dir dir);
};

#endif // SNAKE_HPP_DEFINED
