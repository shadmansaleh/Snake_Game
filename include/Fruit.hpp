#ifndef FRUIT_HPP_DEFINED
#define FRUIT_HPP_DEFINED

#include "Entity.hpp"
#include <utility>


class Fruit : public Entity {
public:
  Fruit(double x, double y);

  void draw(sf::RenderWindow&);
  void tick(double dt);
};

#endif // FRUIT_HPP_DEFINED
