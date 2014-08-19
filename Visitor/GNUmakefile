include GNUmakefile.unittest
CXX = g++
CXXFLAGS = -Wall -g -O0 -pthread -Wextra

SOURCES := main.cpp
OBJECTS := $(SOURCES:.cpp=.o)
APP := Visitor

SOURCES := $(patsubst %,src/%,${SOURCES})
OBJECTS := $(patsubst %,obj/%,${OBJECTS})
APP := $(patsubst %,bin/%,${APP})

# Here source
all: $(SOURCES) $(APP)

$(APP): $(OBJECTS) bin
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

#.cpp.o:
obj/%.o:src/%.cpp obj
	$(CXX) $(CXXFLAGS) -c $< -o $@

bin:
	@mkdir bin

obj:
	@mkdir obj

.PHONY: clean
clean:
	rm -rf obj
