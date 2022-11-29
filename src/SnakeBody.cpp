#include "SnakeBody.hpp"
#include <utility>

void SnakeBody::move(std::pair<int, int> &mv) { move_vector = mv; }
std::pair<int, int> SnakeBody::get_move_vec() { return move_vector; }
