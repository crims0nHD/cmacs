#ifndef EVENTHANDLER_H_
#define EVENTHANDLER_H_

#include <stdint.h>

extern uint32_t eh_create(char *name);
extern uint32_t eh_getEventId(char *name);
extern uint32_t eh_delete(uint32_t eventid);

extern uint16_t eh_subscribe(uint32_t eventid, void (*functionToCall)());
extern uint16_t eh_unsubscribe(uint32_t eventid, void (*functionToCall)());

extern void eh_call(uint32_t eventid);

#endif // EVENTHANDLER_H_
