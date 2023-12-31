NAME	= so_long 
CFLAGS	= -g -Wextra -Wall -Werror
LIBMLX	= ./MLX42
LIBFT   = ./definitive_libft/

HEADERS	= $(LIBFT)/get_next_line.h
LIBS	= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	= src/test.c definitive_libft/get_next_line.c definitive_libft/get_next_line_utils.c definitive_libft/ft_split.c
OBJS	= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c $(HEADERS) 
	$(CC) $(CFLAGS) $< -c -o $@ 

$(NAME) : $(OBJS)
	$(CC) $(OBJS) $(LIBS) $(HEADERS) ; mv a.out $(NAME)

clean:
	rm -rf $(OBJS)
	rm -rf $(LIBMLX)/build

fclean: clean
	rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
