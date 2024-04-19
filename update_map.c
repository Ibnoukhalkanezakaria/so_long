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

void    update_map(int key, t_stack *game)
{
    if(key == 'd')
        mlx_xpm_file_to_image(game->mlx, "images/player2-l.xpm", &game->width, &game->height);
    else if(key == 's')
        mlx_xpm_file_to_image(game->mlx, "images/player2.xpm" , &game->width, &game->height);
    else if(key == 'a')
        mlx_xpm_file_to_image(game->mlx, "images/player2.xpm", &game->width, &game->height);
    else if(key == 'w')
        mlx_xpm_file_to_image(game->mlx, "images/player2-l.xpm ", &game->width, &game->height);
}

void    key_d(t_stack *game)
{
    update_map('d', game);
    if (game->map[game->y_play][game->x_play] == 'E' && game->num == 0)
	{
		game->map[game->y_play][game->x_play - 1] = '0';
		map_draw(game);
	}
	else if (game->map[game->y_play][game->x_play] == '1'
			|| game->map[game->y_play][game->x_play] == 'E')
		game->x_play -= 1;
	else
	{
		if (game->map[game->y_play][game->x_play] == 'C')
			game->num -= 1;
		game->map[game->y_play][game->x_play] = 'P';
		game->map[game->y_play][game->x_play - 1] = '0';
		map_draw(game);
	}
}

void    key_s(t_stack *game)
{
    update_map('s', game);
	if (game->map[game->y_play][game->x_play] == 'E' && game->num == 0)
	{
		game->map[game->y_play - 1][game->x_play] = '0';
		map_draw(game);
	}
	else if (game->map[game->y_play][game->x_play] == '1'
			|| game->map[game->y_play][game->x_play] == 'E')
		game->y_play -= 1;
	else
	{
		if (game->map[game->y_play][game->x_play] == 'C')
			game->num -= 1;
		game->map[game->y_play][game->x_play] = 'P';
		game->map[game->y_play - 1][game->x_play] = '0';
		map_draw(game);
	}
}

void    key_a(t_stack *game)
{
    update_map('a', game);
    if (game->map[game->y_play][game->x_play] == 'E' && game->num)
	{
		game->map[game->y_play][game->x_play + 1] = '0';
		map_draw(game);
	}
	else if (game->map[game->y_play][game->x_play] == '1'
			|| game->map[game->y_play][game->x_play] == 'E')
		game->x_play += 1;
	else
	{
		game->map[game->y_play][game->x_play] = 'P';
		game->map[game->y_play][game->x_play + 1] = '0';
		map_draw(game);
	}
}

void    key_w(t_stack *game)
{
    update_map('w', game);
    if (game->map[game->y_play][game->x_play] == 'E' && game->num == 0)
	{
		game->map[game->y_play + 1][game->x_play] = '0';
		map_draw(game);
	}
	else if (game->map[game->y_play][game->x_play] == '1'
			|| game->map[game->y_play][game->x_play] == 'E')
		game->y_play += 1;
	else
	{
		if (game->map[game->y_play][game->x_play] == 'C')
			game->num -= 1;
		game->map[game->y_play][game->x_play] = 'P';
		game->map[game->y_play + 1][game->x_play] = '0';
		map_draw(game);
	}
}
