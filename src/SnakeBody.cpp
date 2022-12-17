#include "SnakeBody.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <utility>
#include <array>

void SnakeBody::move(Dir mv) { move_vector = mv; }
Dir SnakeBody::get_move_dir() { return move_vector; }

void SnakeBody::draw(sf::RenderWindow& win) {
  auto sprite = (*sprites)[sprite_id.first][sprite_id.second];
  sprite.setPosition((posX+.5f) * BlockWidth, (posY+.5f) * BlockHeight);
  sprite.setRotation(sprite_rotate);
  win.draw(sprite);
}

void SnakeBody::tick() {
  auto cur_pos = this->get_pos();
  cur_pos.first += dirs[this->move_vector].first * this->move_speed;
  cur_pos.second += dirs[this->move_vector].second * this->move_speed;
  this->set_pos(cur_pos);
}
