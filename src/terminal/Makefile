SRCS := $(wildcard *.c)
OBJS := $(patsubst %.c, ../../obj/terminal/%.o, $(SRCS))
INCLUDES := -I../../include

.DEFAULT_GOAL := terminal
.PHONY := dirs terminal

terminal: dirs $(OBJS)
	@echo $(OBJS)

../../obj/terminal/%.o: %.c
	gcc $(INCLUDES) -c -g -o $@ $<

dirs:
	mkdir -p ../../obj/terminal
