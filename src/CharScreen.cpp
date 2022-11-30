#include "CharScreen.hpp"
#include <cstdlib>

// initiates screen by allocating required memory and cleaning terminal
void CharScreen::init(int W, int H) {
  if (H > 0 && W > 0) {
    height = H;
    width = W;
    scr = (char *)std::malloc((H + 1) * (W + 1) * sizeof(char));
    if (scr) {
      std::memset(scr, ' ', (height + 1) * (width + 1));
      oldScr = (char *)std::malloc((H + 1) * (W + 1) * sizeof(char));
      if (oldScr) {
        std::memset(oldScr, 0, (height + 1) * (width + 1));
        clearTerminal();
        refresh();
      } else
        setDefault();
    } else
      setDefault();
  } else
    setDefault();
}
// returns the value of a char in x,y location of screen
char CharScreen::getVal(char *sc, int x, int y) {
  // check if input is valid
  if (sc && x <= width && y <= height && x >= 0 && y >= 0) {
    // width+1 is required to make the last char of line and the first char of
    // line differ
    return *(sc + (((width + 1) * y) + x));
  } else
    return 0;
}
// opposite of getVal it change a char in a location
inline int CharScreen::setVal(char *sc, int x, int y, char ch) {
  if (sc && x <= width && y <= height && x >= 0 && y >= 0) { // same as getVal
    *(sc + (((width + 1) * y) + x)) = ch;
    return 1;
  } else
    return -1;
}
// it is used to reset the screen or to destruct it . It sets default values
void CharScreen::setDefault() {
  if (scr)
    free(scr);
  if (oldScr)
    free(oldScr);
  scr = NULL;
  oldScr = NULL;
  height = 0;
  width = 0;
}

// draws one char at a time on the screen using ansi escape sequence
void CharScreen::draw(int x, int y) {
  if (x <= width && y <= height && x >= 0 &&
      y >= 0) { //\x1b[b;aH sends sursor to (a,b) location
    std::cout << "\x1b[" << y + ofsetY << ";" << x + ofsetX << "H"
              << getVal(scr, x, y) << std::flush;
  }
}
// clears the terminal below screen
void CharScreen::clearBottom() {
  if (height > 0 && width > 0) {
    std::cout << "\x1b[" << height + 1 << "B"
              << "\x1b[J"
              << "\x1b[" << height + 1 << ";0H" << std::flush;
  }
}
// Constructor just calls init
CharScreen::CharScreen(int W, int H) {
  //  if(maxHeight <= 0 || maxWidth <= 0)
  getMaxHW();
  init(W, H);
}

CharScreen::CharScreen() {
  //  if(maxHeight <= 0 || maxWidth <= 0)
  getMaxHW();
  init(maxHeight, maxWidth);
  //  setDefault();
}
// destructor just calls setDefault
CharScreen::~CharScreen() { setDefault(); }
// resets screen
void CharScreen::getNewScreen(int W, int H) {
  setDefault();
  init(W, H);
}
// clears the screen . just puts spaces everywhere .
int CharScreen::clear() {
  if (scr) {
    memset(scr, ' ', height * width);
    return 1;
  } else
    return -1;
}
// fills the screen with one char
int CharScreen::fillScreen(char ch) {
  if (scr) {
    memset(scr, ch, height * width);
    refresh();
    return 1;
  } else
    return -1;
}

// clears terminal with escape sequence
void CharScreen::clearTerminal() { std::cout << "\x1b[H\x1b[J" << std::flush; }
// updates a single location with a char
int CharScreen::update(int x, int y, char ch) { return setVal(scr, x, y, ch); }
// adds a string to certain position in screen
int CharScreen::update(int x, int y, char *ch) {
  int len = std::strlen(ch);
  if (width >= (x + len)) {
    for (int i = 0; i <= len; ++i, ch++)
      setVal(scr, x + i, y, *ch);
    return 1;
  } else
    return -1;
}
// adds a string at certain line
int CharScreen::update(int y, char *ch) { return update(0, y, ch); }
// refreshes the screen
void CharScreen::refresh(int keepOld) {
  for (int i = 0; i <= height; ++i)
    for (int j = 0; j <= width; ++j) {
      if (getVal(scr, j, i) != getVal(oldScr, j, i)) {
        draw(j, i);
        setVal(oldScr, j, i, getVal(scr, j, i));
      }
    }
  if (!keepOld)
    clear();
  clearBottom();
}

// get max height and max width
void CharScreen::getMaxHW() {
  struct winsize size;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
  maxHeight = size.ws_col;
  maxWidth = size.ws_row;
  /* size.ws_row is the number of rows, size.ws_col is the number of columns. */
}
