#include <ncurses.h>
#include "view.h"
#include "io.h"

struct Game {
  int scene;

};

struct Game initgame() {
  struct Game ret;
  ret.scene = 1;

  return ret;
};

void setup() {
  initgame();
  initscr();
  noecho();
  curs_set(0);
  keypad(stdscr, TRUE);
}

int gameloop() {
  while(true) {
    if (draw(input()) > 0) {
      return(1);
    }
  }
  return(0);
}
