#include "CharScreen.hpp"

int main() {
  CharScreen sc(20, 40);
  sc.clear();
  sc.update(19, 1, "Hello world");
  sc.refresh();
}
