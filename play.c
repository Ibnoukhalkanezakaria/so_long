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

void    get_events(int key, t_stack *game)
{
    if(key == KEY_D)
    {
        key_d(game);
    }
    else if(key == KEY_S)
    {
        key_s(game);
    }
    else if(key == KEY_A)
    {
        key_a(game);
    }
    else if(key == KEY_W)
    {
        key_w(game);
    }
}

int ft_moves(int key, t_stack *game)
{
    get_events(key, game);
    // ft_printf("Moves :%d\n", game->moves++);
}

void    play(t_stack *game)
{
    mlx_hook(game->win, 02, 1L<<0, ft_moves ,game);
}
