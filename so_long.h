#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "minilibx-linux/mlx.h"

typedef struct so_long
{
    void    *mlx;
    void    *win;
    char    **map;
    int     width;
    int     height;
    void    *back_img;
    void    *box_img;
    void    *hero_img;
    int     moves;
}   t_stack;

#define KEY_D 100
#define KEY_S 115
#define KEY_W 119
#define KEY_A 97

char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
void    create_window(t_stack *game);
char**    read_map(char *path, t_stack *game);
void    play(t_stack *game);
int	ft_printf(const char *format, ...);
void    key_d(t_stack *game);
void    key_s(t_stack *game);
void    key_a(t_stack *game);
void    key_w(t_stack *game);
void    update_map(int key, t_stack *game);
void    get_events(int key, t_stack *game);

#endif
