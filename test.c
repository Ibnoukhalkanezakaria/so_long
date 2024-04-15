/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:58:10 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/03/22 15:01:47 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>

#define KEY_D 100
#define KEY_S 115

void    draw_game(t_stack *game)
{
    int y = 0;
    while (game->map[y])
    {
        int x = 0;
        while (game->map[y][x])
        {
            if(game->map[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->back_img, x*32, y*32);
            else if(game->map[y][x] == '0')
                mlx_put_image_to_window(game->mlx, game->win, game->wall_img, x*32, y*32);
            else if(game->map[y][x] == 'P')
                mlx_put_image_to_window(game->mlx, game->win, game->player_img, x*32, y*32);
            else if(game->map[y][x] == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->img1_img, x*32, y*32);
            else if(game->map[y][x] == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->img2_img, x*32, y*32);
            else 
                return;
            x++;
        }
        y++;
    }
}

void    put_images(t_stack *game)
{
    game->back_img = mlx_xpm_file_to_image(game->mlx, "images/0.xpm", &game->width, &game->height);
    game->wall_img = mlx_xpm_file_to_image(game->mlx, "images/1.xpm", &game->width, &game->height);
    game->player_img = mlx_xpm_file_to_image(game->mlx, "images/0.xpm", &game->width, &game->height);
    game->img1_img = mlx_xpm_file_to_image(game->mlx, "images/0.xpm", &game->width, &game->height);
    game->img2_img = mlx_xpm_file_to_image(game->mlx, "images/block.xpm", &game->width, &game->height);  
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
