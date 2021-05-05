#include "logger.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static FILE *f_logfile = NULL;
static bool initialized = false;
static bool stdoutecho = false;
static uint32_t logcount = 0;
static uint16_t lformat = 0;

uint32_t loginit(char *logpath, uint16_t format, bool echoToStdout) {
  if (initialized)
    return -1;

  if (logpath != NULL)
    f_logfile = fopen(logpath, "a");

  lformat = format;
  initialized = true;
  stdoutecho = echoToStdout;

  return 0;
}

uint32_t logexit() {
  if (!initialized)
    return -1;

  if (f_logfile != NULL)
    fclose(f_logfile);

  initialized = false;
  f_logfile = NULL;
  lformat = 0;
  stdoutecho = false;

  return 0;
}

void writetofile(char *message) { fprintf(f_logfile, "%s\n", message); }

void writetostdout(char *message) { fprintf(stdout, "%s\n", message); }

void writelog(uint16_t loglevel, char *message) {
  char *msgstring = malloc(sizeof(char) + 100 + strlen(message));
  char *msgoffset = msgstring;

  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  if (lformat & FORMAT_LOGNUMBER) {
    msgoffset += sprintf(msgoffset, "[%d] ", logcount);
  }

  if (lformat & FORMAT_DATE) {
    msgoffset += sprintf(msgoffset, "[%02d.%02d.%04d] ", tm.tm_mday,
                         tm.tm_mon + 1, tm.tm_year + 1900);
  }

  if (lformat & FORMAT_TIME) {

    msgoffset += sprintf(msgoffset, "[%02d:%02d:%02d] ", tm.tm_hour, tm.tm_min,
                         tm.tm_sec);
  }

  if (lformat & FORMAT_LOGLEVEL) {
    if (loglevel == 0)
      msgoffset += sprintf(msgoffset, "[%s]", "MESSAGE");
    else if (loglevel == 1)
      msgoffset += sprintf(msgoffset, "[%s]", "WARNING");
    else if (loglevel == 2)
      msgoffset += sprintf(msgoffset, "[%s]", "ERROR");
  }

  if (f_logfile != NULL) {
    writetofile(msgstring);
  }

  if (stdoutecho) {
    writetostdout(msgstring);
  }

  free(msgstring);
  logcount++;
}

uint32_t logmessage(char *message) {
  if (!initialized)
    return -1;

  writelog(0, message);
  return 0;
}

uint32_t logwarning(char *message) {
  if (!initialized)
    return -1;

  writelog(1, message);
  return 0;
}

uint32_t logerror(char *message) {
  if (!initialized)
    return -1;

  writelog(2, message);
  return 0;
}
