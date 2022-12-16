#include "SnakeBody.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <utility>
#include <array>

std::pair<int, int> dirs[] = {
  std::make_pair(0, -1),
  std::make_pair(0, 1),
  std::make_pair(-1, 0),
  std::make_pair(1, 0)
};

void SnakeBody::move(Dir mv) { move_vector = mv; }
Dir SnakeBody::get_move_dir() { return move_vector; }

void SnakeBody::draw(sf::RenderWindow& win) {
  sf::RectangleShape rect(sf::Vector2<float>(BlockWidth, BlockHeight));
  rect.setPosition(posX * BlockWidth, posY * BlockHeight);
  rect.setFillColor(sf::Color::Cyan);
  win.draw(rect);
}

void SnakeBody::tick(double dt) {
  auto cur_pos = this->get_pos();
  cur_pos.first += dirs[this->move_vector].first * this->move_speed * dt;
  cur_pos.second += dirs[this->move_vector].second * this->move_speed * dt;
  this->set_pos(cur_pos);
}
