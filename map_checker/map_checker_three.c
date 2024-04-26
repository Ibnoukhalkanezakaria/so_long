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

#include "../so_long.h"

int	count_lines(t_stack *game)
{
	int	i;
	int	count;
	int	size;

	i = 0;
	count = 0;
	size = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != size)
			count++;
		i++;
	}
	return (count);
}

int	check_one(t_stack *game)
{
    int i;
    int count;
    int count2;

	i = 0;
    count = 0;
    count2 = 0;
	while (game->map[i])
	{
        int j = 0;
        while (game->map[i][j])
        {
            if(game->map[i][j] == '1' 
            || game->map[i][j] == '0' 
            || game->map[i][j] == 'C' 
            || game->map[i][j] == 'P'
            || game->map[i][j] == 'E'
            )
                return 1;
            j++;
        }
		i++;
	}
    return 0;
}

int	map_checker_three(t_stack *game)
{
	int	count;
	int check;

	check = check_one(game);
	count = count_lines(game);
	if (count > 0 && !check)
		return (0);
	return (1);
}
