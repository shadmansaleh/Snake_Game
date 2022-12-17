#ifndef SNAKE_BODY_HPP_DEFINED
#define SNAKE_BODY_HPP_DEFINED

#include <utility>
#include "Entity.hpp"
#include "Utils.hpp"


class SnakeBody : public Entity {
public:
  SnakeBody(int x, int y) : Entity(x, y) {}
  void move(Dir mv);
  Dir get_move_dir();

  void draw(sf::RenderWindow&);
  void tick(double);

private:
  int move_speed = 1;
  Dir move_vector;
  std::pair<int, int> sprite_id;
  float sprite_rotate = 0;

  friend class Snake;
};

#endif // SNAKE_BODY_HPP_DEFINED
