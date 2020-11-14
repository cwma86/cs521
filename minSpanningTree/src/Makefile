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

subdir: $(OBJECTS)
	for dir in $(SUBDIRS) ; do \
		echo $$dir ; \
		if ( ls $$dir/Makefile 2> /dev/null ); then \
			make -C $$dir; \
		else \
			echo "No Make file in directory"; \
		fi; \
	done ;

$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) $(FLAGS) $(DEBUGFLAGS) -c $(SOURCES) $(LIB_PATH) $(LIBS)

all: $(subdir)

clean:
	rm -f $(TARGET) $(OBJECTS)
	for dir in $(SUBDIRS) ; do \
		if ( ls $$dir/Makefile 2> /dev/null ); then \
			make clean -C $$dir ; \
		else \
			echo "No Make file in directory"; \
		fi; \
	done
