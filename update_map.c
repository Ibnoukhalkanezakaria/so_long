/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:56:18 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/03/22 15:07:46 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_image(char key, t_stack *game)
{
	mlx_destroy_image(game->mlx, game->player_img);
	if (key == 'w')
		game->player_img = mlx_xpm_file_to_image(game->mlx,
				"textures/player2.xpm", &game->width, &game->height);
	else if (key == 's')
		game->player_img = mlx_xpm_file_to_image(game->mlx,
				"textures/player2-l.xpm", &game->width, &game->height);
	else if (key == 'd')
		game->player_img = mlx_xpm_file_to_image(game->mlx,
				"textures/player2.xpm", &game->width, &game->height);
	else if (key == 'a')
		game->player_img = mlx_xpm_file_to_image(game->mlx,
				"textures/player2-l.xpm", &game->width, &game->height);
	if (!game->player_img)
	{
		ft_printf("%s\n", "Error\nInvalid image");
		exit_the_game(game);
	}
}

void	key_s(t_stack *game)
{
	if (game->the_stars == 0 && game->map[game->y_play
			+ 1][game->x_play] == 'E')
	{
		ft_printf("Moves: %d\n", game->moves++);
		exit_the_game(game);
	}
	if (game->map[game->y_play][game->x_play] == 'P' && game->map[game->y_play
		+ 1][game->x_play] != '1' && game->map[game->y_play
		+ 1][game->x_play] != 'E')
	{
		game->map[game->y_play][game->x_play] = '0';
		game->map[game->y_play + 1][game->x_play] = 'P';
		ft_printf("Moves: %d\n", game->moves++);
	}
	map_draw(game);
}

void	key_w(t_stack *game)
{
	if (game->the_stars == 0 && game->map[game->y_play
			- 1][game->x_play] == 'E')
	{
		ft_printf("Moves: %d\n", game->moves++);
		exit_the_game(game);
	}
	if (game->map[game->y_play][game->x_play] == 'P' && game->map[game->y_play
		- 1][game->x_play] != '1' && game->map[game->y_play
		- 1][game->x_play] != 'E')
	{
		game->map[game->y_play][game->x_play] = '0';
		game->map[game->y_play - 1][game->x_play] = 'P';
		ft_printf("Moves: %d\n", game->moves++);
	}
	map_draw(game);
}

void	key_d(t_stack *game)
{
	update_image('d', game);
	if (game->the_stars == 0 && game->map[game->y_play][game->x_play
		+ 1] == 'E')
	{
		ft_printf("Moves: %d\n", game->moves++);
		exit_the_game(game);
	}
	if (game->map[game->y_play][game->x_play] == 'P'
		&& game->map[game->y_play][game->x_play + 1] != '1'
		&& game->map[game->y_play][game->x_play + 1] != 'E')
	{
		game->map[game->y_play][game->x_play] = '0';
		game->map[game->y_play][game->x_play + 1] = 'P';
		ft_printf("Moves: %d\n", game->moves++);
	}
	map_draw(game);
}

void	key_a(t_stack *game)
{
	update_image('a', game);
	if (game->the_stars == 0 && game->map[game->y_play][game->x_play
		- 1] == 'E')
	{
		ft_printf("Moves: %d\n", game->moves++);
		exit_the_game(game);
	}
	if (game->map[game->y_play][game->x_play] == 'P'
		&& game->map[game->y_play][game->x_play - 1] != '1'
		&& game->map[game->y_play][game->x_play - 1] != 'E')
	{
		game->map[game->y_play][game->x_play - 1] = 'P';
		game->map[game->y_play][game->x_play] = '0';
		ft_printf("Moves: %d\n", game->moves++);
	}
	map_draw(game);
}
