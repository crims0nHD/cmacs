#include "controlFlowEvents.h"
#include "core/eventhandler.h"
#include "eventhandler.h"
#include "logger.h"
#include "terminal/tui.h"
#include "types/null.h"
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

static void setupApp() {
  loginit(NULL, FORMAT_LOGNUMBER, true);
  logmessage("Starting application...");

  ehandlerinit();
  setupEvents();

  tuiinit();
}

int main(int argc, char **argv) {
  srand(time(NULL));
  setupApp();

  eh_call(eh_getEventId("render"), NULL);
  eh_call(eh_getEventId("redraw"), NULL);

  sleep(5);

  // do emergency exit from main...
  // NOTE: this should probably never happen
  eh_call(eh_getEventId("halt"), NULL);
  return 0;
}
