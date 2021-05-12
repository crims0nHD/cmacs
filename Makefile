.DEFAULT_GOAL := build
.PHONY := build clean
.IGNORE := run

BIN_PATH := ./bin/cmacs

DIRS:=$(wildcard src/*/.)
DIRS_SHELL=$(ls -d src/*)

OBJS=$(shell find obj/ -type f -print)

build: 
	mkdir -p ./bin
	@echo $(DIRS)
	-$(foreach dir, $(DIRS),$(shell $(MAKE) -C $(dir)))
	gcc -g -lncurses -o $(BIN_PATH) $(OBJS)

clean:
	-rm -r ./obj
	-rm -r ./bin

run:
	./bin/cmacs

debug:
	gdb ./bin/cmacs
