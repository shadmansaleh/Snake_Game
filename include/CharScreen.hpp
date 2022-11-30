// Header Guard
#ifndef CHAR_SCREEN_H_DEFINED
#define CHAR_SCREEN_H_DEFINED

// required headers
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>

class CharScreen {
public:
  CharScreen(int W, int H);
  CharScreen();
  ~CharScreen();
  int getHeight() { return height; }
  int getWidth() { return width; }
  int clear();
  int update(int x, int y, char ch);
  int update(int x, int y, char *ch);
  int update(int y, char *ch);
  void refresh(int keepOld = 0);
  void getNewScreen(int W, int H);
  int fillScreen(char ch);
  void clearTerminal();
  void shiftScreenLocX(int x = 1) {
    if (ofsetX + x + width <= maxWidth)
      ofsetX += x;
  }
  void shiftScreenLocY(int y = 1) {
    if (ofsetY + y + height <= maxHeight)
      ofsetY += y;
  }

private:
  char *scr = NULL;
  char *oldScr = NULL;
  int height{0};
  int width{0};
  int maxHeight{0};
  int maxWidth{0};
  int ofsetX{0};
  int ofsetY{0};
  void draw(int x, int y);
  void init(int W, int H);
  void setDefault();
  char getVal(char *sc, int x, int y);
  inline int setVal(char *sc, int x, int y, char ch);
  void getMaxHW();
  void clearBottom();
};

#endif /* ifndef CHAR_SCREEN_H_DEFINED */
