CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++17 -pedantic -g
LDFLAGS=
SOURCES=myfind.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=myfind

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

.PHONY: all clean
