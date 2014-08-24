# default target
all:

include GNUmakefile.unittest

CXX = g++
CXXFLAGS = -Wall -g -O0 -pthread -Wextra -I $(INCLUDE)

SOURCES := main.cpp
OBJECTS := $(SOURCES:.cpp=.o)
APP := Visitor
INCLUDE := src
#SOURCES := $(patsubst %,src/%,${SOURCES})
OBJECTS := $(patsubst %,obj/%,${OBJECTS})
APP := $(patsubst %,bin/%,${APP})
VPATH = src

# Here source
all: $(APP) $(APPTEST)

$(APP): $(OBJECTS) bin
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

obj/%.o: %.cpp obj
	$(CXX) $(CXXFLAGS) -c $< -o $@

bin:
	@mkdir bin

obj:
	@mkdir obj

.PHONY: clean check-syntax
clean:
	rm -rf obj
	rm -f $(APP) $(APPTEST)

check-syntax:
	$(CXX) -o nul -S $(CHK_SOURCES)
