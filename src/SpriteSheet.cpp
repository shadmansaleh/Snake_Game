#include "Utils.hpp"
#include "SpriteSheet.hpp"
#include <stdexcept>

SpriteSheet::SpriteSheet(std::string imgFile, int imgWidth, int imgHeight, int spriteWidth, int spriteHeight) {
  int rows = imgHeight / spriteHeight;
  int cols = imgWidth / spriteWidth;
  textures.resize(cols, std::vector<sf::Texture>(rows));
  sprites.resize(cols, std::vector<sf::Sprite>(rows));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (!textures[i][j].loadFromFile(imgFile, sf::IntRect(j * spriteWidth, i * spriteHeight, spriteWidth, spriteHeight))) {
        throw std::runtime_error("Unable to load sprite");
      }
      sprites[i][j].setTexture(textures[i][j]);
      sprites[i][j].setScale(sf::Vector2f(static_cast<float>(BlockWidth) / spriteWidth,
                                          static_cast<float>(BlockHeight) / spriteHeight));
    }
  }
}

const std::vector<sf::Sprite>& SpriteSheet::operator[](int row) const {
  return sprites[row];
}
