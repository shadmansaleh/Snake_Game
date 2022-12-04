#include "Game.hpp"
#include "Snake.hpp"
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <iostream>

const int BlockWidth = 30, BlockHeight = 30;
const int MapWidth = 40, MapHeight = 23;
constexpr int FPS = 60;

using sf::Keyboard;

Game::Game() :
  win(sf::VideoMode(MapWidth * BlockWidth, MapHeight * BlockHeight), "Snake Game"),
  snake(MapWidth/2, MapHeight/2),
  fruit(15, 10) {
  win.setFramerateLimit(FPS);
  state = GameState::RUNNING;
}

void Game::run() {
  sf::Clock clk;
  int frametime = 1000 / FPS;
  while (state != GameState::QUIT && win.isOpen()) {
    auto now = clk.getElapsedTime().asMilliseconds();
    if (now < frametime) {
      sf::sleep(sf::milliseconds(frametime - now));
    }
    now = clk.getElapsedTime().asMilliseconds();
    clk.restart();
    game_loop(static_cast<double>(now) / 1000);
  }
}

void Game::game_loop(double dt) {
  // handle events
  sf::Event event;
  while (win.pollEvent(event)) {
    if (event.type == sf::Event::Closed)
      win.close();
    else if (event.type == sf::Event::Resized) {
      win.setSize(sf::Vector2<uint>(event.size.width, event.size.height));
    } else if (event.type == sf::Event::KeyPressed) {
      handle_keyboard(event);
    }
  }

  if (state == GameState::PAUSED) return;
  // Update
  snake.tick(dt);

  // redraw
  win.clear(sf::Color(100, 180, 80, 200));
  snake.draw(win);
  fruit.draw(win);
  win.display();
}

void Game::handle_keyboard(sf::Event event) {
  switch (event.key.code) {
    case Keyboard::Q:
    case Keyboard::Escape:
      win.close();
      break;
    case Keyboard::Down:
    case Keyboard::S:
      snake.move(Dir::DOWN);
      break;
    case Keyboard::Up:
    case Keyboard::W:
      snake.move(Dir::UP);
      break;
    case Keyboard::Left:
    case Keyboard::A:
      snake.move(Dir::LEFT);
      break;
    case Keyboard::Right:
    case Keyboard::D:
      snake.move(Dir::RIGHT);
      break;
    case Keyboard::Space:
      if (state == GameState::PAUSED) {
        state = GameState::RUNNING;
      } else if (state == GameState::RUNNING){
        state = GameState::PAUSED;
      }
      break;
    default:
      std::cout << "KeyPress not handled" << std::endl;
  }
}
