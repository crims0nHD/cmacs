#ifndef WINDOW_H_
#define WINDOW_H_

#include "types/pri.h"
#include "types/vectors.h"
#include <stdbool.h>

#include "window/buffer.h"

struct window {
  vec2_t pos;
  vec2_t size;
  u32 priority;
  struct buffer *buffer;

  bool isFocused;
};

#endif // WINDOW_H_
