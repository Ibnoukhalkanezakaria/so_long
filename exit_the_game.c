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

static void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	exit_the_game(t_stack *game)
{
	// free_map(game->map);
	// mlx_destroy_image(game->mlx, game->back_img);
	// mlx_destroy_image(game->mlx, game->exit_img);
	// mlx_destroy_image(game->mlx, game->player_img);
	// mlx_destroy_image(game->mlx, game->img1_img);
	// mlx_destroy_image(game->mlx, game->wall_img);
	// mlx_destroy_window(game->mlx, game->win);
	// mlx_destroy_display(game->mlx);
	// free(game->mlx);
	exit(0);
	return ;
}