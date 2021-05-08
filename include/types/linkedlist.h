#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdint.h>

struct ll_node {
  struct ll_node *lastnode;
  struct ll_node *nextnode;
  void *content;
};

typedef struct ll_node ll_node;

extern ll_node *l_addafter(ll_node *prev, void *content);
extern ll_node *l_addbefore(ll_node *next, void *content);
extern void l_delete(ll_node *n);

// Get first element where content matches
// Returns NULL if not found
extern ll_node *l_get(ll_node *searchstart, void *content);

extern ll_node *l_next(ll_node *n);
extern ll_node *l_prev(ll_node *n);

extern ll_node *l_head(ll_node *n);
extern ll_node *l_tail(ll_node *n);

#endif // LINKEDLIST_H_
