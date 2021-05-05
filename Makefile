.DEFAULT_GOAL := build
.PHONY := build clean

DIRS := $(wildcard src/*/.)

build: $(DIRS)

%:
	$(MAKE) -C $<

clean:
	rm -r ./obj
	rm -r ./bin
