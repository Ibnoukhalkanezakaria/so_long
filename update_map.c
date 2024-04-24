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

static void	update_map(char key, t_stack *game)
{
	if (key == 'd')
		game->player_img = mlx_xpm_file_to_image(game->mlx,
				"images/player2.xpm", &game->width, &game->height);
	else if (key == 'a')
		game->player_img = mlx_xpm_file_to_image(game->mlx,
				"images/player2-l.xpm", &game->width, &game->height);
}

void	key_a(t_stack *game)
{
	update_map('a', game);
	if ((game->y_play == game->x_door && game->x_play == game->y_door)
		&& game->the_stars == 0)
		exit_the_game(game);
	else if ((game->map[game->y_play][game->x_play]) && game->num == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->y_play][game->x_play + 1] = '0';
		map_draw(game);
	}
	else if (game->map[game->y_play][game->x_play] == '1'
		|| game->map[game->y_play][game->x_play] == 'E')
		game->x_play += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->y_play][game->x_play] = 'P';
		game->map[game->y_play][game->x_play + 1] = '0';
		map_draw(game);
	}
}

void	key_d(t_stack *game)
{
	update_map('d', game);
	if ((game->y_play == game->x_door && game->x_play == game->y_door)
		&& game->the_stars == 0)
		exit_the_game(game);
	else if (game->map[game->y_play][game->x_play] == 'E' && game->num == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->y_play][game->x_play - 1] = '0';
		map_draw(game);
	}
	else if (game->map[game->y_play][game->x_play] == '1'
		|| game->map[game->y_play][game->x_play] == 'E')
		game->x_play -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->y_play][game->x_play] = 'P';
		game->map[game->y_play][game->x_play - 1] = '0';
		map_draw(game);
	}
}

void	key_s(t_stack *game)
{
	if ((game->y_play == game->x_door && game->x_play == game->y_door)
		&& game->the_stars == 0)
		exit_the_game(game);
	else if (game->map[game->y_play][game->x_play] == 'E' && game->num == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->y_play - 1][game->x_play] = '0';
		map_draw(game);
	}
	else if (game->map[game->y_play][game->x_play] == '1'
		|| game->map[game->y_play][game->x_play] == 'E')
		game->y_play -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->y_play][game->x_play] = 'P';
		game->map[game->y_play - 1][game->x_play] = '0';
		map_draw(game);
	}
}

void	key_w(t_stack *game)
{
	if ((game->y_play == game->x_door && game->x_play == game->y_door)
		&& game->the_stars == 0)
		exit_the_game(game);
	else if (game->map[game->y_play][game->x_play] == 'E' && game->num == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->y_play + 1][game->x_play] = '0';
		map_draw(game);
	}
	else if (game->map[game->y_play][game->x_play] == '1'
		|| game->map[game->y_play][game->x_play] == 'E')
		game->y_play += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->y_play][game->x_play] = 'P';
		game->map[game->y_play + 1][game->x_play] = '0';
		map_draw(game);
	}
}
