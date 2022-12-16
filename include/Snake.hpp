#ifndef SNAKE_HPP_DEFINED
#define SNAKE_HPP_DEFINED

#include "SnakeBody.hpp"
#include "Utils.hpp"
#include <stdexcept>
#include <vector>
#include <exception>

class Snake {
private:
  std::vector<SnakeBody> body;
  double dt;
  bool move_lock = false; // allow move dir to change only once per tick

  void enlarge(); 

public:
  Snake(int snake0x, int snake0y);

  void draw(sf::RenderWindow &);
  void tick(double dt);
  bool check_hit_body();
  void move(Dir dir);

  friend class Game;
};

#endif // SNAKE_HPP_DEFINED
