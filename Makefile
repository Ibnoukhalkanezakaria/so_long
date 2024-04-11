CC = gcc 
GFLAGS = -Wall -Wextra -Werror
LIBS = -lmlx -lXext -lX11

ft_printf = ft_printf/ft_putchar.c ft_printf/ft_printf_s.c ft_printf/ft_printf_d.c ft_printf/ft_printf_p.c ft_printf/ft_printf_u.c ft_printf/ft_printf_x.c ft_printf/ft_printf_xx.c ft_printf/ft_printf.c

all: so_long

so_long: main.c play.c read_map.c get_next_line/*.c libft/ft_strdup.c libft/ft_strlen.c libft/ft_split.c create_window.c
	$(CC) $(CFLAGS) $^ $(ft_printf) -o $@ $(LIBS)

clean:
	rm -f so_long
