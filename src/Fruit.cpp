#include "Fruit.hpp"
#include "SnakeBody.hpp"
#include "Utils.hpp"
#include <cmath>
#include <stdexcept>
#include <cstdlib>

Fruit::Fruit(int x, int y) : Entity(x, y) {}

void Fruit::draw(sf::RenderWindow& win) {
  auto food = (*sprites)[3][2];
  food.setPosition((posX+0.5) * BlockWidth, (posY+0.5) * BlockHeight);
  win.draw(food);
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
