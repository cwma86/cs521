CC    = g++
FLAGS        = -std=c++11
CFLAGS       = -fPIC -g -Wall -Wextra
LDFLAGS      = -W
LIBS +=
SUBDIRS = $(shell ls -d */)

DEBUGFLAGS   = -O0 -D _DEBUG
RELEASEFLAGS = -O2 -D NDEBUG -combine -fwhole-program

TARGET  = SortTest
OBJECTS = $(shell find . -name '*.o')

$(TARGET): subdirs
	$(CC) $(FLAGS) $(CFLAGS) $(DEBUGFLAGS) -o $(TARGET) $(OBJECTS) $(LDFLAGS) $(LIBS)

subdirs:
	for dir in $(SUBDIRS) ; do \
		echo $$dir ; \
		make -C  $$dir ; \
	done;

all: $(TARGET)

clean:
	rm -f $(TARGET) $(OBJECTS)
	for dir in $(SUBDIRS) ; do \
		make clean -C  $$dir ; \
	done
