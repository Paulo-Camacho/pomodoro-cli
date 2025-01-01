GXX = g++
CXXFLAGS = -std=c++17 -Iinclude -Wall -Wextra -Werror
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
BUILD_DIR = build
SRC_DIR = src
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))
TARGET = timer

# Targets
all: $(BUILD_DIR) $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -r $(BUILD_DIR) $(TARGET)

.PHONY: all clean
