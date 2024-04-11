/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:56:18 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/03/19 23:49:32 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    draw_game(t_stack *game)
{
    int y = 0;
    while (game->map[y])
    {
        int x = 0;
        while (game->map[y][x])
        {
            if(game->map[y][x] == '1')
            {
                mlx_put_image_to_window(game->mlx, game->win, game->box_img, x*16, y*16);
            }
            else if(game->map[y][x] == '0')
                mlx_put_image_to_window(game->mlx, game->win, game->back_img, x*16, y*16);
            else if(game->map[y][x] == 'H')
                mlx_put_image_to_window(game->mlx, game->win, game->hero_img, x*16, y*16);
            else 
                return;
            x++;
        }
        y++;
    }
}

void    put_images(t_stack *game)
{
    game->back_img = mlx_xpm_file_to_image(game->mlx, "images/Dirt.xpm", &game->width, &game->height);
    game->box_img = mlx_xpm_file_to_image(game->mlx, "images/Grass2.xpm", &game->width, &game->height);
    game->hero_img = mlx_xpm_file_to_image(game->mlx, "images/Tree.xpm", &game->width, &game->height);  
}

void    create_window(t_stack *game)
{
    void    *mlx;
    void    *win;

    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, game->width , game->height, "Window Shopper");
    put_images(game);
    draw_game(game);
}