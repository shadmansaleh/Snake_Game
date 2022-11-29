// Header Guard
#ifndef ENTITY_HPP_DEFINED
#define ENTITY_HPP_DEFINED

// required headers
#include <utility>

// abstract base entity class
class Entity {
public:
  Entity(double x, double y) : posX{x}, posY{y} {}
  std::pair<double, double> get_pos();
  virtual void draw() = 0;
  virtual void tick(double dt) = 0;

protected:
  void set_pos(double x, double y);

private:
  double posX, posY;
};

#endif /* ifndef ENTITY_HPP_DEFINED */
