/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game_two.c                                    :+:      :+:    :+:   */
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
		free(map[i++]);
	free(map);
}

static void	free_visited(t_stack *game)
{
	int	i;

	i = 0;
	while (i < game->maph)
		free(game->visited[i++]);
	free(game->visited);
}

int	exit_game_two(t_stack *game)
{
	free_visited(game);
	free_map(game->map);
	free(game->mlx);
	exit(0);
	return (0);
}
