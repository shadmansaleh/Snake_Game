#ifndef FRUIT_HPP_DEFINED
#define FRUIT_HPP_DEFINED

#include "Entity.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <map>
#include <utility>


class Fruit : public Entity {
public:
  Fruit(int x, int y);
  Fruit();
  ~Fruit();

  void draw(sf::RenderWindow&);
  void tick(double);
  void reposition(std::map<std::pair<int, int>, bool> &restricted);

private:
  sf::Texture *mouse_tex;
  sf::Sprite mouse_sprite;

  void init();
};

#endif // FRUIT_HPP_DEFINED
