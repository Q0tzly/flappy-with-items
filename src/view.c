#include <ncurses.h>
#include "view.h"

int scene = 1;

int draw(char ch) {
  erase();
  
  switch (scene) {
    case 2:
      game_scene(ch);
      break;
    case 1:
      title_scene(ch);
      break;
    case 3:
      menu_scene(ch);
      break;
    case 4:
      score_scene(ch);
      break;
    case 0:
      return(1);
      break;
    default:
      return(2);
      break;
  }
  
  refresh();

  return (0);
}

/*
0: end app
1: title
2: game playing
3: menu
4: score(result)
*/

int title_scene(char ch) {
  printw("Title");

  if (ch == '\n') scene = 2;
  if (ch == 'q') scene = 0;

  return (0);
}

int game_scene(char ch) {
  printw("Game");

  if (ch == 27) scene = 3;
  if (ch == 'd') scene = 4;

  return (0);
}

int menu_scene(char ch) {
  printw("Menu");

  if (ch == 27) scene = 2;
  if (ch == 'q') scene = 1;

  return (0);
}

int score_scene(char ch) {
  printw("Score");

  if (ch == '\n') scene = 1;

  return (0);
}
