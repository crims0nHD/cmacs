SRCS := $(wildcard *.c)
OBJS := $(patsubst %.c, ../../obj/types/%.o, $(SRCS))
INCLUDES := -I../../include

.DEFAULT_GOAL := types
.PHONY := dirs types

types: dirs $(OBJS)
	@echo $(OBJS)

../../obj/types/%.o: %.c
	gcc $(INCLUDES) -c -o $@ $<

dirs:
	mkdir -p ../../obj/types
