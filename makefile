NAME	=	push_swap

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra
LIBFT	=	./lib

LIB		=	$(LIBFT)/libft.a
HEADER	=	-I $(LIBFT)/includes

SRCS	=	src/main.c \
			src/push_swap.c \
			src/utils.c

OBJS	=	$(SRCS:.c=.o)

RM		=	rm -rf

all: $(NAME)

libft:
	@make -C $(LIBFT)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) $(HEADER) -o $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $< ${HEADERS}

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re