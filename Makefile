SUBDIRS := src

all: $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@

.PHONY: all $(SUBDIRS)

clean:
	$(MAKE) -C src clean

install:
	cp src/recat /usr/bin/recat