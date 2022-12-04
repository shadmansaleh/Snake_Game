#include "Snake.hpp"
#include "SnakeBody.hpp"

constexpr double SNAKE_TICK_PERIOD = 1.0;

Snake::Snake(int snake0x, int snake0y) {
  // initialize a snake with length 3
  body.clear();
  body.push_back(SnakeBody(snake0x, snake0y));
  body.push_back(SnakeBody(snake0x-1, snake0y));
  body.push_back(SnakeBody(snake0x-2, snake0y));
  body.push_back(SnakeBody(snake0x-3, snake0y));
  body.push_back(SnakeBody(snake0x-4, snake0y));
  body.push_back(SnakeBody(snake0x-5, snake0y));
  // set all of the pices to move to right
  for (auto &x: body) {
    x.move(Dir::RIGHT);
  }
}

void Snake::draw(sf::RenderWindow& window) {
  for (auto &body_piece: body) {
    body_piece.draw(window);
  }
}

void Snake::tick(double dt) {
  this->dt += dt;
  if (this->dt < SNAKE_TICK_PERIOD) return;
  this->dt -= SNAKE_TICK_PERIOD;
  for (auto &body_piece: body) {
    body_piece.tick(SNAKE_TICK_PERIOD);
  }
  for (int i=body.size()-1; i > 0; i--) {
    body[i].move(body[i-1].get_move_dir());
  }
}

void Snake::move(Dir dir) {
  auto cur_dir = body[0].get_move_dir();
  if (dir == cur_dir
      || (cur_dir == Dir::UP && dir == Dir::DOWN)
      || (cur_dir == Dir::DOWN && dir == Dir::UP)
      || (cur_dir == Dir::LEFT && dir == Dir::RIGHT)
      || (cur_dir == Dir::RIGHT && dir == Dir::LEFT)) {
    return;
  }
  body[0].move(dir);
}
