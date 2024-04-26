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

#include "so_long.h"

static int	semu_x(t_stack *game)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				x = i;
			j++;
		}
		i++;
	}
	return (x);
}

static int	semu_y(t_stack *game)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				y = j;
			j++;
		}
		i++;
	}
	return (y);
}

static void	size_window_two(t_stack *game)
{
	int	i;

	game->mapw = ft_strlen(game->map[0]) * 64;
	i = 0;
	while (game->map[i])
		i++;
	game->maph = i * 64;
}

void	delete(t_stack *game)
{
	int	x;
	int	y;

	game->xx = semu_x(game);
	game->yy = semu_y(game);
	game->collect_found = 0;
	size_window_two(game);
}
