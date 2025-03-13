# Compiler
CXX=g++

# Flags
CXXFLAGS=-std=c++17 -g -pedantic -Wall -Wextra
LDFLAGS=-lsfml-system -lsfml-window -lsfml-graphics

# Source files
SOURCES=main.cpp Timer.cpp Ask.cpp Buttom.cpp

# Object files
OBJECTS=$(SOURCES:.cpp=.o)

# Executable
EXECUTABLE=exec

# Default target
all: $(EXECUTABLE)
	./exec

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXECUTABLE) $(LDFLAGS)

# Compiling each source file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
