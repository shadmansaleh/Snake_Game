#include "Utils.hpp"
#include "SpriteSheet.hpp"
#include <stdexcept>

SpriteSheet::SpriteSheet(std::string imgFile, int spriteWidth, int spriteHeight) {
  texture = new sf::Texture;
  if (!texture->loadFromFile(imgFile)) {
    throw std::runtime_error("Unable to load sprite");
  }
  int rows = texture->getSize().y / spriteHeight;
  int cols = texture->getSize().x / spriteWidth;
  sprites.resize(cols, std::vector<sf::Sprite>(rows));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      sprites[i][j].setTexture(*texture);
      sprites[i][j].setTextureRect(sf::IntRect(j * spriteWidth, i * spriteHeight, spriteWidth, spriteHeight));
      sprites[i][j].setScale(sf::Vector2f(static_cast<float>(BlockWidth) / spriteWidth,
                                          static_cast<float>(BlockHeight) / spriteHeight));
      sprites[i][j].setOrigin(static_cast<float>(spriteWidth)/2, static_cast<float>(spriteHeight)/2);
    }
  }
}


SpriteSheet::~SpriteSheet() {
  delete texture;
}

const std::vector<sf::Sprite>& SpriteSheet::operator[](int row) const {
  return sprites[row];
}
