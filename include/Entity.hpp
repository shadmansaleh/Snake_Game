// Header Guard
#ifndef ENTITY_HPP_DEFINED
#define ENTITY_HPP_DEFINED

// required headers
#include <cmath>
#include <utility>
#include <SFML/Graphics.hpp>

// abstract base entity class
class Entity {
public:
  Entity(double x, double y);
  std::pair<double, double> get_pos();
  virtual void draw(sf::RenderWindow&) = 0;  // draw the entity
  virtual void tick(double dt) = 0;  // update the entity
  friend bool operator==(Entity &x, Entity &y); // collision detection

protected:
  void set_pos(std::pair<double, double> &pos);
  double posX, posY;
};

#endif /* ifndef ENTITY_HPP_DEFINED */
