#ifndef FOOD_HPP_DEFINED
#define FOOD_HPP_DEFINED

#include "Entity.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <map>
#include <utility>


class Food : public Entity {
public:
  Food(int x, int y);
  Food();
  ~Food();

  void draw(sf::RenderWindow&);
  void tick(double);
  void reposition(std::map<std::pair<int, int>, bool> &restricted);

private:
  sf::Texture *mouse_tex;
  sf::Sprite mouse_sprite;

  void init();
};

#endif // FOOD_HPP_DEFINED
