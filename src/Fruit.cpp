#include "Fruit.hpp"
#include "Utils.hpp"
#include <cmath>

Fruit::Fruit(double x, double y) : Entity(x, y) {}

void Fruit::draw(sf::RenderWindow& win) {
  double block_radius = std::sqrt(BlockHeight*BlockHeight + BlockWidth * BlockWidth);
  sf::CircleShape fruit(block_radius/4);
  fruit.setFillColor(sf::Color::Red);
  fruit.setPosition(posX * BlockWidth+block_radius/8, posY * BlockHeight+block_radius/8);
  win.draw(fruit);
}

void Fruit::tick(double) {}
