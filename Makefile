NAME	= so_long 
CFLAGS	= -g -Wextra -Wall -Werror
LIBMLX	= ./MLX42
LIBFT   = ./definitive_libft/
SRC_FILES   = ./src/

HEADERS	= $(LIBFT)/get_next_line.h #&& $(SRC_FILES)main.h
LIBS	= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	= src/main.c src/parsing_map.c src/moves.c src/images.c src/check_content_map.c src/parsing_map_utils.c src/main_utils.c src/error_and_free.c definitive_libft/get_next_line.c definitive_libft/get_next_line_utils.c definitive_libft/ft_split.c definitive_libft/ft_strdup.c definitive_libft/ft_strlcpy.c definitive_libft/ft_putstr_fd.c definitive_libft/ft_putchar_fd.c definitive_libft/ft_putstr.c definitive_libft/ft_putnbr.c definitive_libft/ft_putchar.c definitive_libft/ft_printf.c 
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
