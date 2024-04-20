#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>
#include "mlx.h"

typedef struct so_long
{
    void    *mlx;
    void    *win;
    char    **map;
    int     width;
    int     height;
    void    *back_img;
    void    *wall_img;
    void    *player_img;
    void    *img1_img;
    void    *door_img;
    int map_height;
    int map_width;
    int     moves;
    int     end;
    int     y_play;
    int     x_play;
    int     num;
    bool    check;
    int     the_stars;
    void    *exit_img;
}   t_stack;

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
void    create_window(t_stack *game);
char**    read_map(char *path);
void    play(t_stack *game);
int	ft_printf(const char *format, ...);
void    key_d(t_stack *game);
void    key_s(t_stack *game);
void    key_a(t_stack *game);
void    key_w(t_stack *game);
void    update_map(char key, t_stack *game);
void    get_events(int key, t_stack *game);
int	map_draw(t_stack *game);


#endif
