#include "Snake.hpp"
#include "SnakeBody.hpp"
#include "Utils.hpp"

#include <iostream>
#include <utility>
static constexpr double SNAKE_TICK_PERIOD = 0.15;

Snake::Snake(int snake0x, int snake0y) {
  // initialize a snake with length 3
  body.clear();
  for (int i=0; i < 10; i++) {
    body.push_back(SnakeBody(snake0x-i, snake0y));
    body[i].move(Dir::RIGHT);
  }
  set_sprite(0, 0);
  for (int i=1; i < (int)body.size()-1; i++) {
    set_sprite(i-1, i);
  }
  set_sprite(body.size()-2, body.size()-1);
  this->dt = 0;
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
  set_sprite(0, 0);
  for (int i=1; i < (int)body.size()-1; i++) {
    set_sprite(i-1, i);
  }
  set_sprite(body.size()-2, body.size()-1);
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
  set_sprite(body.size()-3, body.size()-2, true);
  set_sprite(body.size()-2, body.size()-1);
}

void Snake::set_sprite(int prev, int cur, bool no_rotate) {
  if (cur == 0) {
    body[cur].sprite_id = std::make_pair((cur == 0 ? 0 : 1), 0);
    if (no_rotate) return;
    body[cur].sprite_rotate = body[cur].get_move_dir() * 90.0f;
    return;
  }
  if (cur == (int)body.size() - 1) {
    body[cur].sprite_id = std::make_pair((cur == 0 ? 0 : 1), 0);
    body[cur].sprite_rotate = body[cur-1].get_move_dir() * 90.0f;
    return;
  }
  auto prev_dir = body[prev].get_move_dir();
  auto cur_dir = body[cur].get_move_dir();
  if (prev_dir == cur_dir) {
    body[cur].sprite_id = std::make_pair(3, 0);
    if (no_rotate) return;
    body[cur].sprite_rotate = 0.0f;
    if (prev_dir == Dir::LEFT || prev_dir == Dir::RIGHT) {
      body[cur].sprite_rotate = 90.0f;
    }
  } else {
    body[cur].sprite_id = std::make_pair(2, 0);
    if (no_rotate) return;
    if (prev_dir == Dir::LEFT) {
      body[cur].sprite_rotate = (cur_dir == Dir::DOWN ? 270.0f : 180.0f);
    } else if (prev_dir == Dir::RIGHT) {
      body[cur].sprite_rotate = (cur_dir == Dir::DOWN ? 0.0f : 90.0f);
    } else if (prev_dir == Dir::UP) {
      body[cur].sprite_rotate = (cur_dir == Dir::RIGHT ? 270.0f : 0.0f);
    } else if (prev_dir == Dir::DOWN) {
      body[cur].sprite_rotate = (cur_dir == Dir::RIGHT ? 180.0f : 90.0f);
    }
  }
}
