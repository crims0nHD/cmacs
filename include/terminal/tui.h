#ifndef TUI_H_
#define TUI_H_

/* Events */
//---------------
// render
// desc: call the render engine
// usage: when modifying the graphics buffer or when changing the screen
// resolution
//
// draw
// desc: draws the rendered framebuffer to the screen
// usage: when screen updates or when render process is done
// NOTE: this should only be used internally
//---------------

extern void tuiinit();
extern void tuiexit();

#endif // TUI_H_
