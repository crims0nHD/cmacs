SRCS := $(wildcard *.c)
OBJS := $(patsubst %.c, ../../obj/core/%.o, $(SRCS))
INCLUDES := -I../../include

.DEFAULT_GOAL := core
.PHONY := dirs core

core: dirs $(OBJS)
	@echo $(OBJS)

../../obj/core/%.o: %.c
	gcc $(INCLUDES) -c -o $@ $<

dirs:
	mkdir -p ../../obj/core
