#ifndef ROCK_HPP
#define ROCK_HPP

#include "Entity.hpp"
#include "Utils.hpp"

class Rock : public Entity {
public:
  Rock(int x, int y);

  void draw(sf::RenderWindow&);
  void tick();
};

#endif // !ROCK_HPP
