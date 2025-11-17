# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinc

# Target executable
TARGET = game

# Source directory
SRC_DIR = src

# Include directory
INC_DIR = inc

# Object directory
OBJ_DIR = obj

# Source files
SOURCES = main.cpp $(SRC_DIR)/AMateria.cpp $(SRC_DIR)/Character.cpp $(SRC_DIR)/MateriaSource.cpp

# Object files
OBJECTS = $(OBJ_DIR)/main.o $(OBJ_DIR)/AMateria.o $(OBJ_DIR)/Character.o $(OBJ_DIR)/MateriaSource.o

# Default target
all: $(OBJ_DIR) $(TARGET)

# Create object directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Build the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compile main.cpp
$(OBJ_DIR)/main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile source files from src/ directory
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -rf $(OBJ_DIR)

# Clean everything including executable
fclean: clean
	rm -f $(TARGET)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re