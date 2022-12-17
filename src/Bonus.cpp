#include "Bonus.hpp"
#include <SFML/Graphics/RectangleShape.hpp>

void Bonus::draw(sf::RenderWindow &win) {
  if (timmer <= 0) return;
  auto bonus = (*sprites)[3][2];
  bonus.setPosition((posX+0.5) * BlockWidth, (posY+0.5) * BlockHeight);
  bonus.setScale(3, 3);
  sf::RectangleShape bar(sf::Vector2f(timmer / 10 * 10*BlockWidth, BlockHeight/2));
  bar.setFillColor(sf::Color::Magenta);
  bar.setPosition(0.5 * BlockWidth, 0.5 * BlockHeight);
  win.draw(bonus);
  win.draw(bar);
}

void Bonus::tick(double dt) {
  if (timmer <= 0) return;
  timmer -= dt;
}

void Bonus::reposition(std::map<std::pair<int, int>, bool> &restricted) {
  Food::reposition(restricted);
  timmer = 5;
}

bool operator==(Bonus &x, Entity &y) {
  return (x.timmer - 0.0f > 1e-6) && x.get_pos().first == y.get_pos().first && x.get_pos().second == y.get_pos().second;
}

bool operator==(Entity &x, Bonus &y) {
  return y == x;
}

