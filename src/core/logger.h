#ifndef LOGGER_H_
#define LOGGER_H_

#include <stdbool.h>
#include <stdint.h>

enum {
  FORMAT_LOGNUMBER = 1 << 0,
  FORMAT_TIME = 1 << 1,
  FORMAT_DATE = 1 << 2,
  FORMAT_LOGLEVEL = 1 << 3
};

extern uint32_t loginit(char *logpath, uint16_t format, bool echoToStdout);
extern uint32_t logexit();

extern uint32_t logmessage(char *message);
extern uint32_t logwarning(char *message);
extern uint32_t logerror(char *message);

#endif // LOGGER_H_
