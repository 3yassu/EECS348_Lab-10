# Compiler
CXX = g++

# Compiler Flags
CXXFLAGS = -std=c++11 -Wall -Wextra

# Source Files
SRC = main.cpp calculator.cpp
OBJ = $(SRC:.cpp=.o)
DEP = calculator.hpp

# Output Executable
TARGET = program

# Rule to build the executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Rule to compile .cpp files into .o files
%.o: %.cpp $(DEP)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJ) $(TARGET)

# PHONY targets (not real files)
.PHONY: clean
