#include "core/eventhandler.h"
#include "logger.h"
#include "types/linkedlist.h"
#include "types/null.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
  uint32_t id;
  char *name;
  ll_node *l_subscribedFunctions; // Pointer to list with subscribed functions
} event;

static ll_node *l_events = NULL;

event *getEventById(uint32_t id) {
  ll_node *search = l_events;
  while (true) {
    if (search != NULL) {
      if (((event *)search->content)->id == id)
        return search->content;
      search = l_next(search);
    } else {
      return NULL;
    }
  }
}

uint32_t createRandomEventId() {
  uint32_t id;
  while (true) {
    id = rand();
    if (!getEventById(id) && id)
      return id;
  }
}

uint32_t eh_create(char *name) {
  if (eh_getEventId(name)) {
    logerror("Tried to create existing event!");
    return 0;
  }

  event *e = malloc(sizeof(event));
  e->id = createRandomEventId();
  e->name = malloc(strlen(name));
  strcpy(e->name, name);
  e->l_subscribedFunctions = NULL;

  ll_node *ln = l_addafter(l_events, e);
  if (l_events == NULL)
    l_events = ln;

  return e->id;
}

uint32_t eh_getEventId(char *name) {
  ll_node *search = l_events;
  while (true) {
    if (search != NULL) {
      if (strcmp(((event *)search->content)->name, name) == 0)
        return ((event *)search->content)->id;
      search = l_next(search);
    } else {
      return 0;
    }
  }
}

uint32_t eh_delete(uint32_t eventid) {
  l_delete(l_get(l_events, getEventById(eventid)));
  return 0;
}

uint16_t eh_subscribe(uint32_t eventid, void (*functionToCall)()) {
  event *e = getEventById(eventid);
  ll_node *la = l_addafter(e->l_subscribedFunctions, functionToCall);
  if (e->l_subscribedFunctions == NULL) {
    e->l_subscribedFunctions = la;
  }
  return 0;
}
uint16_t eh_unsubscribe(uint32_t eventid, void (*functionToCall)()) {
  l_delete(l_get(getEventById(eventid)->l_subscribedFunctions, functionToCall));
  return 0;
}

void eh_call(uint32_t eventid) {
  event *e = getEventById(eventid);
  if (e == NULL) {
    return;
  }

  ll_node *lenum = e->l_subscribedFunctions;
  while (lenum != NULL) {
    void (*fptr)() = lenum->content;
    (*fptr)();
    l_next(lenum);
  }
}

uint16_t ehandlerinit() {
  logmessage("Starting Eventhandler...");
  return 0;
}

void ehandlerexit() { logmessage("Exiting Eventhandler..."); }
