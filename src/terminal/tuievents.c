#include "tuievents.h"
#include "core/eventhandler.h"
#include "tuigraphics.h"
#include "tuirender.h"
#include <stdint.h>

static uint32_t evid_redraw;
static uint32_t evid_render;

void tuievents_init() {
  evid_redraw = eh_create("redraw");
  eh_subscribe(evid_redraw, &draw);
  evid_render = eh_create("render");
  eh_subscribe(evid_render, &render);
}

void tuievents_exit() {
  eh_delete(evid_redraw);
  eh_delete(evid_render);
}
