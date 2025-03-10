# Compiler
CXX=g++
# Flags
CXXFLAGS=-std=c++17 -g -pedantic -Wall -Wextra 
LDFLAGS = -lsfml-system -lsfml-window -lsfml-graphics
# Source files
SOURCES=main.cpp Timer.cpp Ask.cpp

# Executable
EXECUTABLE=exec

# Default target
all: $(EXECUTABLE)
	./exec

$(EXECUTABLE): $(SOURCES)
	$(CXX) $(SOURCES) -o $(EXECUTABLE) $(CXXFLAGS)

# Clean
clean:
	rm -f $(EXECUTABLE)
