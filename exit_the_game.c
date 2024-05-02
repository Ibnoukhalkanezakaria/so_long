/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_the_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:56:18 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/03/22 15:07:46 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	free_visited(t_stack *game)
{
	int	i;

	i = 0;
	while (i < game->maph)
		free(game->visited[i++]);
	free(game->visited);
}

int	exit_the_game(t_stack *game)
{
	free_visited(game);
	free_map(game->map);
	if (game->back_img != NULL)
		mlx_destroy_image(game->mlx, game->back_img);
	if (game->wall_img != NULL)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->player_img != NULL)
		mlx_destroy_image(game->mlx, game->player_img);
	if (game->img1_img != NULL)
		mlx_destroy_image(game->mlx, game->img1_img);
	if (game->exit_img != NULL)
		mlx_destroy_image(game->mlx, game->exit_img);
	if (game->exit_img2 != NULL)
		mlx_destroy_image(game->mlx, game->exit_img2);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}
