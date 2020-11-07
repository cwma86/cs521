LDFLAGS      = -W
LIBS +=
SUBDIRS = $(shell ls -d */)
SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)
OBJECTS = $(SOURCES:.cpp=.o)

all: $(OBJECTS)

clean:
	rm -f $(TARGET) $(OBJECTS)
	for dir in $(SUBDIRS) ; do \
		make clean -C  $$dir ; \
	done
