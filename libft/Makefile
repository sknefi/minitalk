SRC			=	ft_memset ft_bzero ft_memcpy ft_memmove ft_memchr ft_memcmp \
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
				get_next_line/get_next_line \
				get_next_line/get_next_line_utils \
				get_next_line/get_next_line_bonus \
				get_next_line/get_next_line_utils_bonus \
				main

SRCS		= $(addsuffix .c, ${SRC})

OBJS		= ${SRCS:.c=.o}

HEADERS		= 	libft.h get_next_line/get_next_line.h \
				ft_printf/libraries/ft_printf.h get_next_line/get_next_line_bonus.h

NAME		= libft.a

CC			= cc -Wall -Wextra -Werror

BUFFER_SIZE = 4096

%.o: %.c ${HEADERS}
			${CC} -D BUFFER_SIZE=${BUFFER_SIZE} -I. -c $< -o ${<:.c=.o}

all:		${NAME}

$(NAME):	${OBJS} ${HEADERS}
			ar rcs ${NAME} ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

