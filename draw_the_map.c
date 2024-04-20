/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:56:18 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/03/22 15:07:46 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_img(t_stack *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, image, x*64, y*64);
}

static void	draw_the_player(t_stack *game, void *image, int x, int y)
{
	game->y_play = y;
    game->x_play = x; 
    draw_img(game, image , x, y);
}

void	sum_the_stars(t_stack *game)
{
	int i = 0;
	int count = 0;
	int j;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if(game->map[i][j] == 'C')
				count++;
			else if(game->map[i][j] == 'E')
			{
				game->x_door = i;
				game->y_door = j;
			}
			j++;
		}
		i++;
	}
	game->the_stars = count;
}

static void	exit_draw(t_stack *game, int x, int y)
{
    if(game->the_stars == 0)
		game->exit_img = mlx_xpm_file_to_image(game->mlx, "images/door.xpm", &game->width, &game->height);
	else
		game->exit_img = mlx_xpm_file_to_image(game->mlx, "images/door3.xpm", &game->width, &game->height);
    draw_img(game, game->exit_img , x, y);
}

int	map_draw(t_stack *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				draw_img(game, game->wall_img, x, y);
			else if (game->map[y][x] == '0')
				draw_img(game, game->back_img, x, y);
			else if (game->map[y][x] == 'P')
				draw_the_player(game, game->player_img, x, y);
			else if (game->map[y][x] == 'C')
				draw_img(game, game->img1_img, x, y);
			else if (game->map[y][x] == 'E')
				exit_draw(game, x, y);
			x++;
		}
		y++;
	}
	sum_the_stars(game);
	return (0);
}
