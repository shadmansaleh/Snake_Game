#include "Entity.hpp"
#include <utility>

Entity::Entity(double x, double y) : posX{x}, posY{y} {}

std::pair<double, double> Entity::get_pos() {
  return std::make_pair(posX, posY);
}
void Entity::set_pos(std::pair<double, double> &pos) {
  posX = pos.first;
  posY = pos.second;
}

bool operator==(Entity &x, Entity &y) {
  return floor(x.posX) == floor(y.posX) && floor(x.posY) == floor(y.posY);
}
