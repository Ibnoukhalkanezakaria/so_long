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

int    count_lines(t_stack *game)
{
    int i = 0;
    int count = 0;
    int size = ft_strlen(game->map[0]);
    while (game->map[i])
    {
        if(ft_strlen(game->map[i]) != size)
            count++;
        i++;
    }
    return count;
}

int    map_checker_three(t_stack *game)
{
    int count = count_lines(game);
    if(count > 0)
        return 0;
    return 1;
}
