#include "Rock.hpp"
#include <SFML/Graphics/RectangleShape.hpp>

Rock::Rock(int x, int y): Entity(x, y) {
  forbidden_blocks.insert({std::make_pair(x, y), true});
}

void Rock::draw(sf::RenderWindow& win) {
  auto rock = (*sprites)[2][3];
  rock.setPosition((posX+0.5) * BlockWidth, (posY+0.5) * BlockHeight);
  win.draw(rock);
}

void Rock::tick(double) {
  throw std::runtime_error("Rock can't tick");
}

