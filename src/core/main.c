#include "controlFlowEvents.h"
#include "core/eventhandler.h"
#include "eventhandler.h"
#include "logger.h"
#include "terminal/tui.h"
#include "types/null.h"
#include "userspace/userspace.h"

#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

static void setupApp() {
  loginit(NULL, FORMAT_LOGNUMBER, true);
  logmessage("Starting application...");

  ehandlerinit();
  setupEvents();

  buffersInit();

  tuiinit();
}

int main(int argc, char **argv) {
  srand(time(NULL));
  setupApp();

  loop();

  // do emergency exit from main...
  // NOTE: this should probably never happen
  eh_call(eh_getEventId("halt"), NULL);
  return 0;
}
