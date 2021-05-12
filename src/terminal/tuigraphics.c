#include "tuirender.h"
#include <ncurses.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int winx = 0;
static int winy = 0;

void draw() {
  int curx, cury;
  getmaxyx(stdscr, cury, curx);
  if (curx != winx || cury != winy) {
    struct fb_properties p;
    p.sizex = curx;
    p.sizey = cury;
    fb_setProperties(p);
    winx = curx;
    winy = cury;
  }

  char *fb = fb_get();
  for (int y = 0; y < winy; y++) {
    mvaddnstr(y, 0, fb, winx);
  }
  refresh();
}

void tuigraphics_init() {
  initscr();
  getmaxyx(stdscr, winy, winx);
  struct fb_properties p;
  p.sizex = winx;
  p.sizey = winy;
  fb_setProperties(p);
}

void tuigraphics_exit() { endwin(); }
