#include <ncurses.h>
#include "game.h"

int main() {
  setup();
  int ret = gameloop();
  endwin();
  return(ret);
}
