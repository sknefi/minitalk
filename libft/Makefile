NAME		= libft.a

# List of source files for libft
LIBFT_SRC 	= ft_memset ft_bzero ft_memcpy ft_memmove ft_memchr ft_memcmp \
          	  ft_strlen ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint \
          	  ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp ft_strlcpy \
          	  ft_strlcat ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr \
          	  ft_strjoin ft_strtrim ft_split ft_itoa ft_strmapi ft_putchar_fd \
          	  ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_striteri \
          	  ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back \
          	  ft_lstdelone ft_lstclear ft_lstiter ft_lstmap \
			  ft_printf/ft_printf \
			  ft_printf/ft_print_formats/ft_print_char \
			  ft_printf/ft_print_formats/ft_print_number \
			  ft_printf/ft_print_formats/ft_print_pointer \
			  ft_printf/ft_print_formats/ft_print_string \
			  get_next_line/get_next_line_bonus \
			  get_next_line/get_next_line_utils_bonus \
			  ft_error \

SRCS 		= $(addsuffix .c, $(LIBFT_SRC))
OBJS 		= $(SRCS:.c=.o)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

PRINTF_DIR	= ./ft_printf
GNL_DIR		= ./get_next_line

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) 

re: fclean all

.phony: all clean fclean re
