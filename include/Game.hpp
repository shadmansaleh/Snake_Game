#ifndef GAME_HPP_DEFINED
#define GAME_HPP_DEFINED

#include <SFML/Graphics.hpp>
#include "Snake.hpp"
#include "Fruit.hpp"
#include "Bonus.hpp"
#include "Utils.hpp"

class Game {
  public:
    Game();

    void run();
  private:
    sf::RenderWindow win;
    Snake snake;
    Fruit fruit;
    GameState state;

    void game_loop(double dt);
    void handle_keyboard(sf::Event event);
};

#endif // GAME_HPP_DEFINED
