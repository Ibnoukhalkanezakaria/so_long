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

int    player_ele(t_stack *game)
{
    int i;
    int j;
    int player_ele;

    i = 0;
    player_ele = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            if(game->map[i][j] == 'P')
            {
                player_ele++;
            }
            j++;
        }
        
        i++;
    }
    return player_ele;
}

int    door_ele(t_stack *game)
{
    int i;
    int j;
    int door_ele;

    i = 0;
    door_ele = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            if(game->map[i][j] == 'E')
            {
                door_ele++;
            }
            j++;
        }
        
        i++;
    }
    return door_ele;
}

int    map_checker(t_stack *game)
{
    int get_player_ele = player_ele(game);
    int get_door_ele = door_ele(game);
    if(get_player_ele == 1 && get_door_ele == 1)
        return 1;
    else
        return 0;
}
