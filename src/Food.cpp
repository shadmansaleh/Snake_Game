#include "Food.hpp"
#include "SnakeBody.hpp"
#include "Utils.hpp"
#include <cmath>
#include <stdexcept>
#include <cstdlib>

Food::Food(int x, int y) : Entity(x, y) { init(); }
Food::Food() : Entity(0, 0) { init(); }

Food::~Food() {
  delete mouse_tex;
}

void Food::draw(sf::RenderWindow& win) {
  mouse_sprite.setPosition((posX+0.5) * BlockWidth, (posY+0.5) * BlockHeight);
  win.draw(mouse_sprite);
}

void Food::tick(double) {
  throw std::runtime_error("Food can't tick");
}

void Food::reposition(std::map<std::pair<int, int>, bool> &restricted) {
  bool found = false;
  while (!found) {
    int randx = rand() % MapWidth;
    int randy = rand() % MapHeight;
    auto cur_pos = std::make_pair(randx, randy);
    if (!restricted[cur_pos] && !forbidden_blocks[cur_pos]) {
      posX = randx;
      posY = randy;
      found = true;
    }
  }
}

void Food::init() {
  mouse_tex = new sf::Texture;
  if (!mouse_tex->loadFromFile("assets/sprites/mouse.png")) {
    throw std::runtime_error("Unable to load sprite");
  }
  mouse_sprite.setTexture(*mouse_tex);
  mouse_sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
  mouse_sprite.setScale(1.5, 1.5);
  mouse_sprite.setOrigin(32/2, 32/2);
}
