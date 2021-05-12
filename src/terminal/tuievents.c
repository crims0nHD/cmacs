#include "tuievents.h"
#include "core/eventhandler.h"
#include "tuigraphics.h"
#include "tuiinput.h"
#include "tuirender.h"
#include "types/pri.h"
#include <stdint.h>

static u32 evid_draw;
static u32 evid_render;
static u32 evid_updateinput;
static u32 evid_getinput;

void tuievents_init() {
  evid_draw = eh_create("draw");
  eh_subscribe(evid_draw, &draw);
  evid_render = eh_create("render");
  eh_subscribe(evid_render, &render);
  evid_updateinput = eh_create("updateinput");
  eh_subscribe(evid_updateinput, &tuireadinput);
  evid_getinput = eh_create("getinput");
  eh_subscribe(evid_getinput, (void *)&tuigetlastinput);
}

void tuievents_exit() {
  eh_delete(evid_draw);
  eh_delete(evid_render);
  eh_delete(evid_updateinput);
  eh_delete(evid_getinput);
}
