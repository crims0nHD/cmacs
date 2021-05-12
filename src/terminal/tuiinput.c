#include "tuiinput.h"
#include "core/logger.h"
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

static struct inputstate *current;

void tuiinputinit() {
  noecho();
  keypad(stdscr, true);
  raw();

  current = malloc(sizeof(struct inputstate));
  current->mods = 0;
  current->c = 0;
}

void tuiinputexit() { free(current); }

void tuireadinput() {
  int cval = getch();
  if (cval == ERR)
    return;

  const char *cn = keyname(cval);
  memset(current, 0, sizeof(struct inputstate));

  if (cval == 27) // META-Prefix
  {
    current->mods |= META;
    cval = getch(); // Next char holds the actual key
    cn = keyname(cval);
  }

  // Get the character
  int nlen = strlen(cn);
  current->c = cn[nlen - 1];

  // Convert to lowercase
  if (current->c > 0x40 && current->c < 0x5B) {
    current->c += 0x20;
  }

  // CTRL
  if (current->c > 0x60 && current->c < 0x7B && nlen > 1) {
    current->mods |= CTRL;
  }
}

void tuigetlastinput(struct inputstate *s) {
  s->mods = current->mods;
  s->c = current->c;
}
