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

int    get_x_y(t_stack *game)
{
    int csize = sum_c(game); 
    int x = game->x_play;
    int y = game->y_play;

    ft_printf("%d         %d\n", x, y);

    return x;
}

void    get_w_h(t_stack *game)
{
    int max_w;
    int max_h;
    int i = 0;
	game->max_w = ft_strlen(game->map[0]);
	i = 0;
	while (game->map[i])
		i++;
	game->max_h = i;
}

t_coin*    stack(t_stack *game, int csize)
{
    t_coin *node = (t_coin*)malloc(sizeof(t_coin) * csize);
    if(node == NULL)
        return NULL;
    int     i;
    int     x; 
    int     y;

    i = 0;
    x = 0;
    while (game->map[x])
    {
        y = 0;
        while (game->map[x][y])
        {
            if (game->map[x][y] == 'C')
            {
                node[i].x = x;
                node[i].y = y;
                node[i].claimed = 0;
                i++;
            }
            y++;
        }
        x++;
    }
    return node;
}

void    map_checker_four(t_stack *game, int x, int y, int csize)
{
    int i = 0;

    i = 0;
    if (x > game->max_w || x < 0 || y > game->max_h || y < 0)
        return;
    if (game->map[x][y] == '-')
        return;
    if (game->map[x][y] == '1')
        return;
    if (game->map[x][y] == 'C')
    {
        while (i < csize)
        {
            if (game->coins[i].x == x && game->coins[i].y == y)
            {
                game->coins[i].claimed = 1;
                break;
            }
            i++;
        }  
    }
    game->map[x][y] = '-';
    map_checker_four(game, x + 1, y, csize);  // Move right
    map_checker_four(game, x - 1, y, csize);  // Move left
    map_checker_four(game, x, y + 1, csize);  // Move down
    map_checker_four(game, x, y - 1, csize);  // Move up
}
