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

int	sum_cc(t_stack *game)
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
			if (game->map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int    get_w(t_stack *game)
{
	game->max_w = ft_strlen(game->map[0]);
    return game->max_w;
}

int    get_h(t_stack *game)
{
    int i;
	i = 0;
	while (game->map[i])
		i++;
	game->max_h = i;
    return game->max_h;
}

void    map_checker_four(t_stack *game, int x, int y)
{   
    if (!game->visited[x][y] && (game->map[x][y] == 'P' 
    || game->map[x][y] == '0' || game->map[x][y] == 'C'))
    {
        game->visited[x][y] = 1;
        if (game->map[x][y] == 'C')
            game->collect_found += 1;
        map_checker_four(game, x + 1, y);  
        map_checker_four(game, x - 1, y); 
        map_checker_four(game, x, y + 1);  
        map_checker_four(game, x, y - 1); 
    }
}

int     check_all(t_stack *game, int x, int y)
{
    int csize = sum_cc(game);

    int map_checker_val = map_checker(game);
    int map_checker_two_val = map_checker_two(game);
    int map_checker_three_val = map_checker_three(game);
    map_checker_four(game, x, y);

    if ((map_checker(game)) && (map_checker_two(game) && (map_checker_three(game)) && (game->collect_found == csize)))
        return 1;
    return 0;
}
