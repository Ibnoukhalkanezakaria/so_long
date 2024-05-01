/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:56:18 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/03/22 14:31:04 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_ele(t_stack *game, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	map_checker(t_stack *game)
{
	int	get_player_ele;
	int	get_door_ele;
	int	get_star_ele;

	get_player_ele = get_ele(game, 'P');
	get_door_ele = get_ele(game, 'E');
	get_star_ele = get_ele(game, 'C');
	if (get_player_ele == 1 && get_door_ele == 1 && get_star_ele > 0
		&& !ft_strlen(game->map[0]) < 2)
		return (1);
	else
		return (0);
}
