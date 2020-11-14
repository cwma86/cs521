LDFLAGS      = -W
LIBS +=
SUBDIRS = $(shell ls -d */)

SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)
OBJECTS = $(SOURCES:.cpp=.o)

subdir: $(OBJECTS)
	for dir in $(SUBDIRS) ; do \
		echo $$dir ; \
		make -C  $$dir ; \
	done ;

all: $(subdir)

clean:
	rm -f $(TARGET) $(OBJECTS)
	for dir in $(SUBDIRS) ; do \
		make clean -C  $$dir ; \
	done
