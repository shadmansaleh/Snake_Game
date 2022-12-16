#ifndef FRUIT_HPP_DEFINED
#define FRUIT_HPP_DEFINED

#include "Entity.hpp"
#include <map>
#include <utility>


class Fruit : public Entity {
public:
  Fruit(int x, int y);

  void draw(sf::RenderWindow&);
  void tick(double dt);
  void reposition(std::map<std::pair<int, int>, bool> &restricted);
};

#endif // FRUIT_HPP_DEFINED
