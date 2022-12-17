#ifndef BONUS_HPP_DEFINED
#define BONUS_HPP_DEFINED

#include "Food.hpp"
#include "Utils.hpp"
#include <utility>


class Bonus : public Food {
public:
  Bonus(int x, int y) : Food(x, y) {}
  Bonus() : Food() {}

  void draw(sf::RenderWindow&);
  void reposition(std::map<std::pair<int, int>, bool> &restricted);
  void tick(double);
  bool operator=(Entity x);
  friend bool operator==(Bonus &x, Entity &y);
  friend bool operator==(Bonus &x, Entity &y);
  friend class Game;

private:
  double timmer = 0;
};

bool operator==(Entity &x, Bonus &y);
bool operator==(Bonus &x, Entity &y);
#endif // BONUS_HPP_DEFINED
