LDFLAGS      = -W
LIBS +=
SUBDIRS = $(shell ls -d */)

SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)
OBJECTS = $(SOURCES:.cpp=.o)

subdir: $(OBJECTS)
	for dir in $(SUBDIRS) ; do \
		echo $$dir ; \
		if ( ls $$dir/Makefile 2> /dev/null ); then \
			make -C  $$dir ; \
		else \
			echo "No Make file in directory"; \
		fi; \
	done ;

all: $(subdir)

clean:
	rm -f $(TARGET) $(OBJECTS)
	for dir in $(SUBDIRS) ; do \
		if ( ls $$dir/Makefile 2> /dev/null ); then \
			make clean -C  $$dir ; \
		else \
			echo "No Make file in directory"; \
		fi; \
	done
