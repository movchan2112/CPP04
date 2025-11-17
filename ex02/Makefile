# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinc

# Target executable
TARGET = abstracts

# Source directory
SRC_DIR = src

# Include directory
INC_DIR = inc

# Source files
SOURCES = $(SRC_DIR)/main.cpp $(SRC_DIR)/Animal.cpp $(SRC_DIR)/Cat.cpp $(SRC_DIR)/Dog.cpp $(SRC_DIR)/Brain.cpp

# Object files
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=%.o)

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compile source files to object files
%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJECTS)

# Clean everything including executable
fclean: clean
	rm -f $(TARGET)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re