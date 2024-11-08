NAME		= libftprintf.a
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

###
MAIN		= ft_printf.c		

F_FORMATS	= ft_print_formats/

FORMATS		= ft_print_char.c		\
				ft_print_number.c	\
				ft_print_pointer.c	\
				ft_print_string.c

F_LIBS		= libraries/

LIBS		= ft_printf.h

SOURCES		= $(addprefix $(F_FORMATS), $(FORMATS)) $(MAIN)

OBJECTS		= $(SOURCES:.c=.o)
###

$(NAME) : $(OBJECTS)
	ar crs $(NAME) $(OBJECTS)

all: $(NAME)

clean:
	rm -f $(OBJECTS)

fclean:
	rm -f $(NAME) $(OBJECTS)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@