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

void    update_map(int key, t_stack *game)
{
    if(key == 'D')
    {
        mlx_xpm_file_to_image(game->mlx, "images/PD.xpm", &game->width, &game->height);
    }
    else if(key == 'S')
    {
        mlx_xpm_file_to_image(game->mlx, "images/PA.xpm", &game->width, &game->height);
    }
    else if(key == 'A')
    {
        mlx_xpm_file_to_image(game->mlx, "images/PA.xpm", &game->width, &game->height);
    }
    else if(key == 'W')
    {
        mlx_xpm_file_to_image(game->mlx, "images/PD.xpm", &game->width, &game->height);
    }
}

void    key_d(t_stack *game)
{
    update_map("D", game);
}

void    key_s(t_stack *game)
{
    update_map("S", game);
}

void    key_a(t_stack *game)
{
    update_map("A", game);
}

void    key_w(t_stack *game)
{
    update_map("W", game);
}
