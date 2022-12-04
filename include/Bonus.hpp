#ifndef BONUS_HPP_DEFINED
#define BONUS_HPP_DEFINED

#include "Fruit.hpp"
#include <utility>


class Bonus : public Fruit {
public:
  Bonus(double x, double y) : Fruit(x, y) {}

  void draw(sf::RenderWindow&);
};

#endif // BONUS_HPP_DEFINED
