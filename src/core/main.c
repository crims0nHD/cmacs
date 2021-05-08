#include "controlFlowEvents.h"
#include "core/eventhandler.h"
#include "logger.h"
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
}

int main(int argc, char **argv) {
  srand(time(NULL));
  setupApp();

  sleep(5);
  eh_call(eh_getEventId("halt"));

  ehandlerexit();
  logmessage("Stopping application from main?");
  logexit();
  return 0;
}
