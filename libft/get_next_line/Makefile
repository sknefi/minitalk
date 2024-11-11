NAME 		= libgnl.a

CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror

SRCS		= get_next_line_bonus.c get_next_line_utils_bonus.c
OBJS		= $(SRCS:.c=.o)

HEADER		= get_next_line_bonus.h

TEST_NAME	= test.out

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)

# Compiling object files with header dependency
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Default target
all: $(NAME)

# Rule to build the test program
test: $(NAME) $(TEST_OBJ)
	$(CC) $(CFLAGS) $(TEST_OBJ) -L. -lgnl -o $(TEST_NAME)

# Clean up
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(TEST_NAME)

re: fclean all

.phony: all clean fclean re
