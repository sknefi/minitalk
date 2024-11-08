# get_next_line Makefile

# Source files
SRC = get_next_line_bonus.c get_next_line_utils_bonus.c
OBJ = $(SRC:.c=.o)

# Output library
NAME = libgnl.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Default target
all: $(NAME)

# Build static library
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
