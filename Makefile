CC = cc 
CFLAGS = -Wall -Wextra -Werror
LIBS = -lmlx -lXext -lX11

SRC = main.c play.c exit_game_three.c read_map.c get_empty.c \
	  get_next_line/get_next_line_utils.c get_next_line/get_next_line.c \
      libft/ft_strdup.c libft/ft_strlen.c libft/ft_split.c libft/ft_memset.c \
	  create_window.c update_map.c draw_the_map.c \
      exit_the_game.c map_checker/map_checker.c \
      exit_game_two.c map_checker/map_checker_two.c \
	  map_checker/map_checker_three.c map_checker/map_check_all.c delete.c \

OBJS = $(SRC:.c=.o)

FT_PRINTF_SRC = ft_printf/ft_putchar.c ft_printf/ft_printf_s.c \
				ft_printf/ft_printf_d.c ft_printf/ft_printf_p.c \
				ft_printf/ft_printf_u.c ft_printf/ft_printf_x.c \
                ft_printf/ft_printf_xx.c ft_printf/ft_printf.c \

FT_PRINTF_OBJ = $(FT_PRINTF_SRC:.c=.o)

all: so_long

so_long: $(OBJS) $(FT_PRINTF_OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(FT_PRINTF_OBJ)

fclean: clean
	rm -rf so_long

re: fclean all