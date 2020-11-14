CC    = g++
FLAGS        = -std=c++11
CFLAGS       = -fPIC -Wall -Wextra
LDFLAGS      = -W
ifeq ($(RELEASE),1)
	DEBUGFLAGS = -O2 -D NDEBUG
else
	DEBUGFLAGS = -g -O0 -D _DEBUG
endif

LIBS +=
SUBDIRS = $(shell ls -d */)
SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)
OBJECTS = $(SOURCES:.cpp=.o)

all: $(OBJECTS)

$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) $(FLAGS) $(DEBUGFLAGS) -c $(SOURCES) $(LIB_PATH) $(LIBS)

clean:
	rm -f $(TARGET) $(OBJECTS)
	for dir in $(SUBDIRS) ; do \
		make clean -C  $$dir ; \
	done
