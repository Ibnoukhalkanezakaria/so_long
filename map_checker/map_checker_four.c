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

void    f(t_stack *game)
{
    int i;
    int j;
    int count;
    bool check = true;

    i = 0;
    count = 0;
    j = 0;
    while (game->map[i])
    {
        // if(game->map[i] == "111111111111111111111" && check )
        // {
            // count++;
        // }
        // ft_printf("%s\n", game->map[i]);
        // j = 0;
        // while (game->map[i][j])
        // {
        //     // if(game->map[i][j])
        //     // {
        //     //     count++;
        //     // }
        //     ft_printf("%c", game->map[i][j]);
        //     j++;
        // }
        
        i++;
    }
    // ft_printf("i: %d\n", i);
    // ft_printf("count: %d\n", count);
}

int    map_checker_four(t_stack *game)
{
    // ft_printf("%d", 546643435);
    f(game);
    return 0;
}
