#include "terminal/tui.h"
#include "tuievents.h"
#include "tuigraphics.h"
#include "tuirender.h"

// Initialize everything needed for the terminal ui to work
// NOTE: this includes event handlers, graphics and input
void tuiinit() {
  tuirender_init();
  tuigraphics_init();
  tuievents_init();
}

// Deinitialize stuff
void tuiexit() {
  tuievents_exit();
  tuirender_exit();
  tuigraphics_exit();
}
