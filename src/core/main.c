#include "logger.h"
#include "types/null.h"
#include <stdbool.h>

int main(int argc, char **argv) {
  loginit(NULL, FORMAT_LOGNUMBER, true);

  logmessage("Hello World");

  logexit();
  return 0;
}
