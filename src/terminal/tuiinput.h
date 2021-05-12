#ifndef TUIINPUT_H_
#define TUIINPUT_H_

#include "terminal/tui.h"
#include "types/pri.h"

extern void tuireadinput();
extern void tuigetlastinput(struct inputstate *s);

extern void tuiinputinit();
extern void tuiinputexit();

#endif // TUIINPUT_H_
