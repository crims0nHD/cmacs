SRCS := $(wildcard *.c)
OBJS := $(patsubst %.c, ../../obj/userspace/%.o, $(SRCS))
INCLUDES := -I../../include

.DEFAULT_GOAL := userspace
.PHONY := dirs userspace

userspace: dirs $(OBJS)
	@echo $(OBJS)

../../obj/userspace/%.o: %.c
	gcc $(INCLUDES) -c -g -o $@ $<

dirs:
	mkdir -p ../../obj/userspace
