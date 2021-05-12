#include "terminal/tui.h"
#include "core/eventhandler.h"
#include "tuievents.h"
#include "tuigraphics.h"
#include "tuiinput.h"
#include "tuirender.h"
#include "types/null.h"

// Initialize everything needed for the terminal ui to work
// NOTE: this includes event handlers, graphics and input
void tuiinit() {
  tuirender_init();
  tuigraphics_init();
  tuiinputinit();
  tuievents_init();
}

// Deinitialize stuff
void tuiexit() {
  tuievents_exit();
  tuiinputexit();
  tuirender_exit();
  tuigraphics_exit();
}
