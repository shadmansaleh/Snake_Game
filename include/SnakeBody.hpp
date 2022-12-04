#ifndef SNAKE_BODY_HPP_DEFINED
#define SNAKE_BODY_HPP_DEFINED

#include <utility>
#include "Entity.hpp"
#include "Utils.hpp"


class SnakeBody : public Entity {
public:
  SnakeBody(double x, double y) : Entity(x, y) {}
  void move(Dir mv);
  Dir get_move_dir();

  void draw(sf::RenderWindow&);
  void tick(double dt);

private:
  double move_speed = 1;
  Dir move_vector;
};

#endif // SNAKE_BODY_HPP_DEFINED
