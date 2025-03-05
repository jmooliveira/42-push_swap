#makefile

NAME	=	push_swap

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra
LIBFT	=	./lib

LIB		=	$(LIBFT)/libft.a
HEADER	=	-I ./lib/includes

SRCS	=	src/main.c \
			src/validates.c \
			src/errors.c \
			src/init.c \
			src/free_memory.c \
			src/op_push.c \
			src/op_swap.c \
			src/op_rotate.c \
			src/op_reverse_rotate.c \
			src/push_swap.c \
			src/until_five_numbers_a.c \
			# src/until_five_numbers_b.c \

OBJS	=	$(SRCS:.c=.o)

RM		=	rm -rf

all: $(NAME)

libft:
	@make -C $(LIBFT)

$(NAME): $(OBJS) libft
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $< ${HEADER}

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
