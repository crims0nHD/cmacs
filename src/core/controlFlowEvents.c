#include "controlFlowEvents.h"
#include "core/eventhandler.h"
#include "logger.h"
#include <stdlib.h>

static void ev_HaltProgram() {
  logmessage("Shutting down due to event called! :)");

  ehandlerexit();
  logexit();
  exit(0);
}

void setupEvents() {
  int evid = eh_create("halt");
  eh_subscribe(evid, &ev_HaltProgram);
}
