NAME		= libftprintf.a

CC			= cc
CFLAGS		= -Wall -Werror -Wextra

SRCS		= ft_printf.c \
			  ft_print_formats/ft_print_char.c \
			  ft_print_formats/ft_print_number.c \
			  ft_print_formats/ft_print_pointer.c \
			  ft_print_formats/ft_print_string.c \

OBJS		= $(SRCS:.c=.o)
HEADER		= ./libraries/ft_printf.h

TEST_NAME	= test.out

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

# Compiling object files with header dependency
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

# Rule to build the test program
test: $(NAME) $(TEST_OBJ)
	$(CC) $(CFLAGS) $(TEST_OBJ) -L. -lftprintf -o $(TEST_NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(TEST_NAME)

re: fclean all

.phony: all clean fclean re