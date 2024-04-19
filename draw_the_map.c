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
	mlx_put_image_to_window(game->mlx, game->win, image, x*32, y*32);
}

static void	draw_the_player(t_stack *game, void *image, int x, int y)
{
	game->y_play = y;
    game->x_play = x; 
    draw_img(game, image , x, y);
}

static void	exit_draw(t_stack *game, int x, int y)
{
    if(game->num == 0)
        game->exit_img = mlx_xpm_file_to_image(game->mlx, "images/1.xpm", &game->width, &game->height);
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
			// else if (game->map[y][x] == 'E')
				// exit_draw(game, x, y);
				// draw_img(game, game->img1_img, x, y);
			// else
			// 	return 0;
			x++;
		}
		y++;
	}
	return (0);
}
