# Source files for client and server
SRC_CLIENT = client ./libft/ft_atoi ./libft/ft_isdigit
SRC_SERVER = server utils

# Convert source file names to .c files
SRCS_CLIENT = $(addsuffix .c, $(SRC_CLIENT))
SRCS_SERVER = $(addsuffix .c, $(SRC_SERVER))

# Convert source file names to object files
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

# Paths and Library
HEADERS = minitalk.h
LIBFTPRINTF_DIR = ./libft/ft_printf
LIBFTPRINTF = $(LIBFTPRINTF_DIR)/libftprintf.a

# Executables
NAME_CLIENT = client.out   # Name of the client executable
NAME_SERVER = server.out   # Name of the server executable

# Compiler settings
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Targets


# Build both client and server executables
all: $(LIBFTPRINTF) $(NAME_CLIENT) $(NAME_SERVER)

# Build client program and link with libftprintf.a
$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -L$(LIBFTPRINTF_DIR) -lftprintf -o $(NAME_CLIENT)

# Build server program and link with libftprintf.a
$(NAME_SERVER): $(OBJS_SERVER) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(OBJS_SERVER) -L$(LIBFTPRINTF_DIR) -lftprintf -o $(NAME_SERVER)

# Compile .c files into .o files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Build libftprintf.a in its directory
$(LIBFTPRINTF):
	$(MAKE) -C $(LIBFTPRINTF_DIR)

# Clean object files in current directory and libftprintf directory
clean:
	rm -f $(OBJS_CLIENT) $(OBJS_SERVER)
	$(MAKE) -C $(LIBFTPRINTF_DIR) clean

# Full cleanup, including executables and libftprintf.a
fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)
	$(MAKE) -C $(LIBFTPRINTF_DIR) fclean

# Rebuild everything
re: fclean all
