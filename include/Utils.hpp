#ifndef UTILS_DIR_HPP
#define  UTILS_DIR_HPP

#include "SpriteSheet.hpp"
enum Dir {UP=0, RIGHT=1, DOWN=2, LEFT=3};
enum GameState {PAUSED, RUNNING, QUIT, INTRO, GAME_OVER};

const extern int BlockWidth, BlockHeight, MapWidth, MapHeight;
extern std::pair<int, int> dirs[];
const extern SpriteSheet *sprites;

#endif // !UTILS_DIR_HPP
