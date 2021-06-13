#ifndef BUFFER_H_
#define BUFFER_H_

#include "types/pri.h"
#include <stdbool.h>

enum {
  BUFFER_WRITABLE = 1 << 0,
  BUFFER_MODIFIED = 1 << 1,
};

struct buffer {
  char *(*render);
  bool rerender;
  u32 options;
};

#endif // BUFFER_H_
