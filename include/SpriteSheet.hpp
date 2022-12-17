#ifndef SPRITE_SHEET_HPP
#define SPRITE_SHEET_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <vector>
#include <string>

class SpriteSheet {
public:
  SpriteSheet(std::string imgFile, int spriteWidth, int spriteHeight);
  ~SpriteSheet();
  const std::vector<sf::Sprite>& operator[](int row) const;

private:
  sf::Texture *texture;
  std::vector<std::vector<sf::Sprite>> sprites;
};
#endif // !SPRITE_SHEET_HPP
