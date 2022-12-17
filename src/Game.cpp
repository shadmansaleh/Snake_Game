#include "SpriteSheet.hpp"
#include "Game.hpp"
#include "Snake.hpp"
#include "Utils.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <utility>
#include <time.h>
#include <string>
#include <cstring>

const int BlockWidth = 32, BlockHeight = 32;
const int MapWidth = 40, MapHeight = 22;
constexpr int FPS = 60;
const SpriteSheet *sprites;

std::map<std::pair<int, int>, bool> forbidden_blocks;


std::pair<int, int> dirs[] = {
  std::make_pair(0, -1),
  std::make_pair(1, 0),
  std::make_pair(0, 1),
  std::make_pair(-1, 0)
};

sf::Texture *backgroundTex;
sf::Sprite backgroundSp;

using sf::Keyboard;

Game::Game() :
  win(sf::VideoMode(MapWidth * BlockWidth, MapHeight * BlockHeight), "Snake Game"),
  snake(MapWidth/2, MapHeight/2),
  score(0) {

  std::srand(std::time(0));
  sprites = new SpriteSheet("assets/sprites/Snake.png", 16, 16);
  font.loadFromFile("assets/fonts/Future TimeSplitters.otf");
  backgroundTex = new sf::Texture;
  backgroundTex->loadFromFile("assets/sprites/Snake.png", sf::IntRect(16*3, 16*3, 16, 16));
  backgroundTex->setRepeated(true);
  backgroundSp.setTexture(*backgroundTex);
  backgroundSp.setTextureRect(sf::IntRect(0, 0, MapWidth * BlockWidth, MapHeight * BlockHeight));
  win.setFramerateLimit(FPS);
  std::map<std::pair<int, int>, bool> restricted;
  for (auto &body_piece: snake.body) {
    restricted[body_piece.get_pos()] = true;
  }
  fruit.reposition(restricted);
  state = GameState::INTRO;
}

Game::~Game() {
  delete sprites;
  delete backgroundTex;
}

void Game::run() {
  float frametime = 1000.0 / FPS;
  sf::Clock clk;
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
      win.setSize(sf::Vector2<unsigned int>(event.size.width, event.size.height));
    } else if (event.type == sf::Event::KeyPressed) {
      handle_keyboard(event);
    }
  }

  // Update
  if (state == GameState::RUNNING) {
    snake.tick(dt);
    bonus.tick(dt);
    if (snake.check_hit_body() || forbidden_blocks[snake.body[0].get_pos()]) {
      state = GameState::GAME_OVER;
    }
    if (snake.body[0] == fruit) {
      snake.enlarge();
      score++;
      std::map<std::pair<int, int>, bool> restricted;
      for (auto &body_piece: snake.body) {
        restricted[body_piece.get_pos()] = true;
      }
      fruit.reposition(restricted);
      if (std::rand() % 5 == 0) {
        bonus.reposition(restricted);
      }
    }
    if (bonus == snake.body[0]) {
      snake.enlarge();
      score += bonus.timmer * 10;
      bonus.timmer = 0;
    }
  }

  // redraw
  win.clear();
  win.draw(backgroundSp);
  {
    sf::Text tx_score;
    char score_txt[20];
    tx_score.setFont(font);
    tx_score.setCharacterSize(BlockHeight * 2);
    tx_score.setFillColor(sf::Color::White);
    std::sprintf(score_txt, "Score:%3d", score);
    tx_score.setPosition((MapWidth - std::strlen(score_txt)+2) * BlockWidth, BlockHeight);
    tx_score.setString(score_txt);

    win.draw(tx_score);
  }
  snake.draw(win);
  fruit.draw(win);
  bonus.draw(win);
  if (state != GameState::RUNNING) {
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(BlockHeight * 2);
    text.setFillColor(sf::Color::White);
    std::string txt;
    if (state == GameState::INTRO) {
      txt = "Press Space To Start Playing";
    } else if (state == GameState::PAUSED) {
      txt = "Paused";
    } else if (state == GameState::GAME_OVER) {
      txt = "GAME OVER";
    }
    text.setPosition((int(MapWidth/2) - int(txt.length()/2) + (state == GameState::INTRO ? 6 : 0)) * BlockWidth, int(MapHeight * 2 / 3) * BlockHeight);
    text.setString(txt);
    win.draw(text);
  }
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
      if (state == GameState::PAUSED || state == GameState::INTRO) {
        state = GameState::RUNNING;
      } else if (state == GameState::RUNNING){
        state = GameState::PAUSED;
      }
      break;
    default:
      break;
  }
}
