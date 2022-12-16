#include "Fruit.hpp"
#include "SnakeBody.hpp"
#include "Utils.hpp"
#include <cmath>
#include <stdexcept>
#include <cstdlib>

Fruit::Fruit(int x, int y) : Entity(x, y) {}

void Fruit::draw(sf::RenderWindow& win) {
  double block_radius = std::sqrt(BlockHeight*BlockHeight + BlockWidth * BlockWidth);
  sf::CircleShape fruit(block_radius/4);
  fruit.setFillColor(sf::Color::Red);
  fruit.setPosition(posX * BlockWidth+block_radius/8, posY * BlockHeight+block_radius/8);
  win.draw(fruit);
}

void Fruit::tick(double) {
  throw std::runtime_error("Fruit can't tick");
}

void Fruit::reposition(std::map<std::pair<int, int>, bool> &restricted) {
  bool found = false;
  while (!found) {
    int randx = rand() % MapWidth;
    int randy = rand() % MapHeight;
    if (!restricted[std::make_pair(randx, randy)]) {
      posX = randx;
      posY = randy;
      found = true;
    }
  }
}
