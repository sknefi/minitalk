NAME		=	minitalk.a

SRCS_CLIENT		=	client.c
SRCS_SERVER		=	server.c utils.c

OBJS_CLIENT		=	$(SRCS_CLIENT:.c=.o)
OBJS_SERVER		=	$(SRCS_SERVER:.c=.o)

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

LIBFT_DIR	=	./libft
LIBFT_NAME	=	libft.a
LIBFT		=	$(LIBFT_DIR)/$(LIBFT_NAME)

all: client server

client: $(OBJS_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJS_CLIENT) $(LIBFT)

server: $(OBJS_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJS_SERVER) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS_CLIENT) $(OBJS_SERVER)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) client server
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
