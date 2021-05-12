#include "types/linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

ll_node *l_addafter(ll_node *prev, void *content) {
  ll_node *lln = malloc(sizeof(ll_node));
  lln->content = content;

  // Setting properties of this node
  lln->lastnode = prev;
  if (prev != NULL)
    lln->nextnode = prev->nextnode;
  else
    lln->nextnode = NULL;

  // Setting properties of adjacent nodes
  if (prev != NULL) {
    if (lln->nextnode != NULL)
      lln->nextnode->lastnode = lln;
    prev->nextnode = lln;
  }

  return lln;
}

ll_node *l_addbefore(ll_node *next, void *content) {
  ll_node *lln = malloc(sizeof(ll_node));
  lln->content = content;

  // Setting properties of this node
  lln->nextnode = next;
  if (next != NULL)
    lln->lastnode = next->nextnode;
  else
    lln->lastnode = NULL;

  // Setting properties of adjacent nodes
  if (next != NULL) {
    if (lln->lastnode != NULL)
      lln->lastnode->nextnode = lln;
    next->lastnode = lln;
  }

  return lln;
}

void l_delete(ll_node *n) {
  ll_node *np = n->lastnode, *nn = n->nextnode;

  if (np != NULL) {
    np->nextnode = nn;
  }

  if (nn != NULL) {
    nn->lastnode = np;
  }

  free(n);
}

ll_node *l_get(ll_node *searchstart, void *content) {
  ll_node *s = searchstart;
  do {
    if (s == NULL)
      break;
    s = l_next(s);
  } while (s->content != content);

  return s;
}

ll_node *l_next(ll_node *n) { return n->nextnode; }

ll_node *l_prev(ll_node *n) { return n->lastnode; }

ll_node *l_head(ll_node *n) {
  ll_node *s = n;
  while (l_next(s) != NULL)
    s = l_next(s);
  return s;
}

ll_node *l_tail(ll_node *n) {
  ll_node *s = n;
  while (l_prev(s) != NULL)
    s = l_prev(s);
  return s;
}
