#ifndef TUI_H_
#define TUI_H_

#include "types/pri.h"

/* Events */
//---------------
// render
// desc: call the render engine
// usage: when modifying the graphics buffer or when changing the screen
// resolution
//
// draw
// desc: draws the rendered framebuffer to the screen
// usage: when screen updates or when render process is done
// NOTE: this should only be used internally
//---------------

extern void tuiinit();
extern void tuiexit();

enum {
  CTRL = 1 << 0,
  META = 1 << 1,
  SHIFT = 1 << 2,
};

struct inputstate {
  u32 mods;
  char c;
};

#endif // TUI_H_
