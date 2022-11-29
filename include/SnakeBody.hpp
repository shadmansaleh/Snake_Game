#ifndef SNAKE_BODY_HPP_DEFINED
#define SNAKE_BODY_HPP_DEFINED

#include "Entity.hpp"
#include <utility>

class SnakeBody : public Entity {
public:
  SnakeBody(double x, double y) : Entity(x, y) {}
  void move(std::pair<int, int> &mv);
  std::pair<int, int> get_move_vec();

  void draw();
  void tick(double dt);

private:
  std::pair<int, int> move_vector;
};

#endif // SNAKE_BODY_HPP_DEFINED
