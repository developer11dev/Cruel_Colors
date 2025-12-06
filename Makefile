# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

# Source and object files
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:src/%.cpp=build/%.o)

# Output program name
TARGET = program

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

build/%.o: src/%.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf build $(TARGET)
