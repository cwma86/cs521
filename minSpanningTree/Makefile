CC    = g++
FLAGS        = -std=c++11
CFLAGS       = -fPIC -g -Wall -Wextra
LDFLAGS      = -W
LIBS +=
SUBDIRS = $(shell ls -d */)

DEBUGFLAGS   = -O0 -D _DEBUG
RELEASEFLAGS = -O2 -D NDEBUG -combine -fwhole-program

TARGET  = minSpanTest
OBJECTS = $(shell find . -name '*.o')

$(TARGET): subdirs
	$(CC) $(FLAGS) $(CFLAGS) $(DEBUGFLAGS) -o $(TARGET) $(OBJECTS) $(LDFLAGS) $(LIBS)

subdirs:
	for dir in $(SUBDIRS) ; do \
		echo $$dir ; \
		if ( ls $$dir/Makefile 2> /dev/null ); then \
			make -C  $$dir ; \
		else \
			echo "No Make file in directory"; \
		fi; \
	done;

all: $(TARGET)

clean:
	rm -f $(TARGET) $(OBJECTS)
	for dir in $(SUBDIRS) ; do \
		if ( ls $$dir/Makefile ); then \
			make clean -C  $$dir ; \
		else \
			echo "No Make file in directory"; \
		fi; \
	done
