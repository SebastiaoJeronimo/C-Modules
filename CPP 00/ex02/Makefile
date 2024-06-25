# Define variables

# Name of the executable
NAME = account

# Compiler to be used
CXX= c++

# Compiler flags
CXXFLAGS = -Werror -Wextra -Wall -std=c++98

# Include paths (commented out in this case)
INC = -I ./inc/

# Source directory
SRC_PATH = src/

# Object directory
OBJ_PATH = obj/

# Find all source files in SRC_PATH directory
SRC = $(wildcard $(SRC_PATH)*.cpp) 

# Generate corresponding object file paths
OBJ = $(patsubst $(SRC_PATH)%.cpp,$(OBJ_PATH)%.o,$(SRC))

# Targets and rules

# Default target to build the executable
all: $(NAME)

# Rule to build the executable
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile each source file into an object file
$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp | $(OBJ_PATH)
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@ 

# Rule to create the object directory if it doesn't exist
$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

# Clean up object files
clean:
	rm -rf $(OBJ_PATH)

# Clean up object files and the executable
fclean: clean
	rm -f $(NAME)

# Clean up and rebuild the project
re: fclean all

dir:
	@mkdir -p $(SRC_PATH)
	@mkdir -p inc/

# Declare phony targets
.PHONY: all clean fclean re
