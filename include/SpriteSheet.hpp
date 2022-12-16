#ifndef SPRITE_SHEET_HPP
#define SPRITE_SHEET_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <vector>
#include <string>

class SpriteSheet {
public:
  SpriteSheet(std::string imgFile, int imgWidth, int imgHeight, int spriteWidth, int spriteHeight);
  const std::vector<sf::Sprite>& operator[](int row) const;

private:
  std::vector<std::vector<sf::Texture>> textures;
  std::vector<std::vector<sf::Sprite>> sprites;
};
#endif // !SPRITE_SHEET_HPP
