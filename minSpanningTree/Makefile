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

TARGET  = minSpanTest
OBJECTS = $(shell find . -name '*.o')

$(TARGET): subdirs
	$(CC) $(FLAGS) $(CFLAGS) $(DEBUGFLAGS) -o $(TARGET) $(OBJECTS) $(LDFLAGS) $(LIBS)

subdirs:
	for dir in $(SUBDIRS) ; do \
		echo $$dir ; \
		if ( ls $$dir/Makefile 2> /dev/null ); then \
			make -C  $$dir; \
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
