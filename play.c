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

static void	get_events(int key, t_stack *game)
{
	if (key == KEY_D)
	{
		game->x_play += 1;
		key_d(game);
	}
	else if (key == KEY_S)
	{
		game->y_play += 1;
		key_s(game);
	}
	else if (key == KEY_A)
	{
		game->x_play -= 1;
		key_a(game);
	}
	else if (key == KEY_W)
	{
		game->y_play -= 1;
		key_w(game);
	}
	else if (key == KEY_Q)
		exit_the_game(game);
}

static int	ft_moves(int key, t_stack *game)
{
	get_events(key, game);
	// ft_printf("Moves:  %d\n", game->moves++);
	return (0);
}

static int	close_win(int key, t_stack *game)
{
	exit_the_game(0);
	return (0);
}

void	play(t_stack *game)
{
	mlx_hook(game->win, 02, 1L << 0, ft_moves, game);
	mlx_hook(game->win, 17, 0, close_win, game);
}
