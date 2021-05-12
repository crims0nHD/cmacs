#include "tuirender.h"
#include "types/linkedlist.h"
#include "types/null.h"
#include "types/pri.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

static char *framebuffer_front, *framebuffer_back;
static struct fb_properties *fb_prop;
static bool hasPropChanged;
static ll_node *l_renderfunction;

static void fb_createOrResize(uint32_t x, uint32_t y) {
  if (!framebuffer_back) {
    framebuffer_back = malloc(sizeof(char) * x * y);
  } else {
    framebuffer_back = realloc(framebuffer_back, sizeof(char) * x * y);
  }
}

static void fb_clear() {
  memset(framebuffer_back, ' ', fb_prop->sizex * fb_prop->sizey);
}

// TODO: remove this
static void placeholder_full(char *framebuffer, u32 sizex, u32 sizey) {
  for (int i = 0; i < sizex * sizey; i++) {
    framebuffer[i] = '#';
  }
}

char *fb_get() { return framebuffer_front; }

void tuirender_init() {
  framebuffer_front = NULL;
  framebuffer_back = NULL;

  fb_prop = malloc(sizeof(struct fb_properties));
  fb_prop->colored = false;
  fb_prop->sizex = 0;
  fb_prop->sizey = 0;

  // TODO: make a function to dynamically add and remove the renderfunctions
  l_renderfunction = l_addafter(NULL, &placeholder_full);

  hasPropChanged = false;
}

void tuirender_exit() {
  // TODO
}

void fb_setProperties(struct fb_properties prop) {
  fb_prop->colored = prop.colored;
  fb_prop->sizex = prop.sizex;
  fb_prop->sizey = prop.sizey;
  hasPropChanged = true;
}

void render() {
  // Check for framebuffer things
  if (!framebuffer_back)
    fb_createOrResize(fb_prop->sizex, fb_prop->sizey);
  else if (hasPropChanged) {
    fb_createOrResize(fb_prop->sizex, fb_prop->sizey);
    hasPropChanged = false;
  }

  // Clear the framebuffer
  fb_clear();

  // Draw to the framebuffer
  if (l_renderfunction) {
    ll_node *n = l_renderfunction;
    while (true) {
      if (!n)
        break;
      else {
        void (*r)(char *, u32, u32) = n->content;
        r(framebuffer_back, fb_prop->sizex, fb_prop->sizey);
        n = l_next(n);
      }
    }
  }

  // Swap framebuffer pointers
  char *fbf = framebuffer_front;
  framebuffer_front = framebuffer_back;
  framebuffer_back = fbf;
}
