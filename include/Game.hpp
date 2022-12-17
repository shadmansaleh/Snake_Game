#ifndef GAME_HPP_DEFINED
#define GAME_HPP_DEFINED

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include "Snake.hpp"
#include "Fruit.hpp"
#include "Bonus.hpp"
#include "Utils.hpp"
#include "SpriteSheet.hpp"

class Game {
  public:
    Game();
    ~Game();

    void run();
  private:
    sf::RenderWindow win;
    sf::Font font;
    Snake snake;
    Fruit fruit;
    Bonus bonus;
    GameState state;
    int score;

    void game_loop(double dt);
    void handle_keyboard(sf::Event event);
    void gen_fruit();
    void gen_bonus();
};

#endif // GAME_HPP_DEFINED
