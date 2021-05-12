#ifndef TUIRENDER_H_
#define TUIRENDER_H_

#include "types/pri.h"

struct fb_properties {
  bool colored;
  u32 sizex;
  u32 sizey;
};

// Get the framebuffer to be used for drawing
extern char *fb_get();

// Call the render method to prepare the framebuffer
extern void render(void *arg);

// Set the properties for the next render process
extern void fb_setProperties(struct fb_properties prop);

// Initializes the render engine
extern void tuirender_init();

// Deinitializes the render engine
extern void tuirender_exit();

#endif // TUIRENDER_H_
