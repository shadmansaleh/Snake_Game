#ifndef FRUIT_HPP_DEFINED
#define FRUIT_HPP_DEFINED

#include "Entity.hpp"
#include <map>
#include <utility>


class Fruit : public Entity {
public:
  Fruit(int x, int y);
  Fruit();

  void draw(sf::RenderWindow&);
  void tick();
  void reposition(std::map<std::pair<int, int>, bool> &restricted);
};

#endif // FRUIT_HPP_DEFINED
