#ifndef GAME_HPP_DEFINED
#define GAME_HPP_DEFINED

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include "Snake.hpp"
#include "Food.hpp"
#include "Bonus.hpp"
#include "Utils.hpp"
#include "Rock.hpp"
#include "SpriteSheet.hpp"
#include <vector>

class Game {
  public:
    Game();
    ~Game();

    void run();
  private:
    sf::RenderWindow win;
    sf::Font font;
    Snake snake;
    Food food;
    Bonus bonus;
    GameState state;
    std::vector<Rock> rocks;
    int score;

    void game_loop(double dt);
    void handle_keyboard(sf::Event event);
};

#endif // GAME_HPP_DEFINED
