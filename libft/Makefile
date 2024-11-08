# List of source files for libft
LIBFT_SRC = ft_memset ft_bzero ft_memcpy ft_memmove ft_memchr ft_memcmp \
            ft_strlen ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint \
            ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp ft_strlcpy \
            ft_strlcat ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr \
            ft_strjoin ft_strtrim ft_split ft_itoa ft_strmapi ft_putchar_fd \
            ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_striteri \
            ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back \
            ft_lstdelone ft_lstclear ft_lstiter ft_lstmap main \

# Source files for libft
LIBFT_SRCS = $(addsuffix .c, $(LIBFT_SRC))

# Header file for libft
LIBFT_HEADER = libft.h

# Object files for libft
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

# Output name for libft static library
LIBFT_NAME = libft.a

# Compiler settings
CC = cc
RM = rm -f
AR = ar rc
CFLAGS = -Wall -Wextra -Werror

# Directories for external libraries (printf and get_next_line)
PRINTF_DIR = ./ft_printf
GNL_DIR = ./get_next_line

# Include Makefiles for printf and get_next_line
PRINTF_MAKE = $(PRINTF_DIR)/Makefile
GNL_MAKE = $(GNL_DIR)/Makefile

# Default target: Compile everything
all: $(LIBFT_NAME) $(PRINTF_DIR)/libftprintf.a $(GNL_DIR)/libgnl.a

# Rule to compile libft
$(LIBFT_NAME): $(LIBFT_OBJS)
	$(AR) $(LIBFT_NAME) $(LIBFT_OBJS)

# Rule to compile each .c file into .o file for libft
%.o: %.c $(LIBFT_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# Include the Makefiles for printf and get_next_line
$(PRINTF_DIR)/libftprintf.a:
	make -C $(PRINTF_DIR)

$(GNL_DIR)/libgnl.a:
	make -C $(GNL_DIR)

# Clean object files for libft
clean:
	$(RM) $(LIBFT_OBJS)
	make -C $(PRINTF_DIR) clean
	make -C $(GNL_DIR) clean

# Clean everything, including libft, printf, and get_next_line
fclean: clean
	$(RM) $(LIBFT_NAME)
	make -C $(PRINTF_DIR) fclean
	make -C $(GNL_DIR) fclean

# Rebuild everything
re: fclean all

# Phony targets (non-file targets)
.PHONY: all clean fclean re

# EXE target: Create the final executable (gnl.out) linking all libraries
EXE_NAME = gnl.out
EXE_SRCS = main.c  # Add your main.c or the relevant entry-point file here

# Compilation rule for final executable
$(EXE_NAME): $(EXE_SRCS)
	$(CC) $(CFLAGS) $(EXE_SRCS) -o $(EXE_NAME) $(PRINTF_DIR)/libftprintf.a $(GNL_DIR)/libgnl.a $(LIBFT_NAME)

