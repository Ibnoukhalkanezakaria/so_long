/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:56:18 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/03/22 14:31:04 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct so_long
{
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
	void	*back_img;
	void	*wall_img;
	void	*player_img;
	void	*img1_img;
	void	*door_img;
	int		map_height;
	int		map_width;
	int		moves;
	int		end;
	int		y_play;
	int		x_play;
	int		x_door;
	int		y_door;
	int		num;
	int		max_w;
	int		max_h;
	int		mapw;
	int		maph;
	int		the_stars;
	int		empty_num;
	int		collect_found;
	int		**visited;
	void	*exit_img;
	int		yy;
	int		xx;
}			t_stack;

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_Q 113

char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *s);
char		*get_next_line(int fd);
char		*ft_strdup(const char *s);
char		*ft_strjoin(const char *s1, const char *s2);
void		create_window(t_stack *game);
char		**read_map(char *path);
void		play(t_stack *game);
int			ft_printf(const char *format, ...);
void		key_d(t_stack *game);
void		key_s(t_stack *game);
void		key_a(t_stack *game);
void		key_w(t_stack *game);
static void	update_map(char key, t_stack *game);
static void	get_events(int key, t_stack *game);
int			map_draw(t_stack *game);
int			exit_the_game(t_stack *game);
static void	free_map(char **map);
int			map_checker(t_stack *game);
int			map_checker_two(t_stack *game);
int			map_checker_three(t_stack *game);
void		map_checker_four(t_stack *game, int x, int y);
int			get_w(t_stack *game);
int			get_h(t_stack *game);
int			semu_y(t_stack *game);
int			semu_x(t_stack *game);
void		free_map(char **map);
int			check_all(t_stack *game, int x, int y);
void delete (t_stack *game);

#endif
