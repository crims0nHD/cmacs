#include "core/eventhandler.h"
#include "terminal/tui.h"
#include "types/null.h"
#include "types/pri.h"
#include "userspace/userspace.h"

static u32 evid_render;
static u32 evid_draw;
static u32 evid_updateinput;
static u32 evid_getinput;

void loop() {
  evid_render = eh_getEventId("render");
  evid_draw = eh_getEventId("draw");
  evid_updateinput = eh_getEventId("updateinput");
  evid_getinput = eh_getEventId("getinput");

  while (true) {
    eh_call(evid_render, NULL);
    eh_call(evid_draw, NULL);

    eh_call(evid_updateinput, NULL);
    struct inputstate s;
    eh_call(evid_getinput, &s);

    if (s.c == 'c' && s.mods & CTRL)
      eh_call(eh_getEventId("halt"), NULL);

    if (s.c == 'c' && s.mods & META)
      eh_call(eh_getEventId("halt"), NULL);
  }
}
