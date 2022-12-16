#include "Snake.hpp"
#include "SnakeBody.hpp"

#include <iostream>
constexpr double SNAKE_TICK_PERIOD = 1.0;
extern std::pair<int, int> dirs[];

Snake::Snake(int snake0x, int snake0y) {
  // initialize a snake with length 3
  body.clear();
  body.push_back(SnakeBody(snake0x, snake0y));
  body.front().move(Dir::RIGHT);
  for (int i=0; i < 10; i++) {
    this->enlarge();
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
  this->move_lock = false;
}

bool Snake::check_hit_body() {
  for (int i=1; i < (int)body.size(); i++) {
    if (body[0] == body[i]) {
      return true;
    }
  }
  return false;
}

void Snake::move(Dir dir) {
  if (this->move_lock) return;
  auto cur_dir = body[0].get_move_dir();
  if (dir == cur_dir
      || (cur_dir == Dir::UP && dir == Dir::DOWN)
      || (cur_dir == Dir::DOWN && dir == Dir::UP)
      || (cur_dir == Dir::LEFT && dir == Dir::RIGHT)
      || (cur_dir == Dir::RIGHT && dir == Dir::LEFT)) {
    return;
  }
  this->move_lock = true;
  body[0].move(dir);
}

void Snake::enlarge() {
  if (body.size() == 0) throw std::runtime_error("No snake to enlarge :/");
  auto last_pos = body.back().get_pos();
  auto last_dir = body.back().get_move_dir();
  body.push_back(SnakeBody(last_pos.first - dirs[last_dir].first,
        last_pos.second - dirs[last_dir].second));
  body.back().move(last_dir);
}
