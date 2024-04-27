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

static void	put_images(t_stack *game)
{
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "images/wall.xpm",
			&game->width, &game->height);
	game->back_img = mlx_xpm_file_to_image(game->mlx, "images/back2.xpm",
			&game->width, &game->height);
	game->player_img = mlx_xpm_file_to_image(game->mlx, "images/player2.xpm",
			&game->width, &game->height);
	game->img1_img = mlx_xpm_file_to_image(game->mlx, "images/star2.xpm",
			&game->width, &game->height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "images/door3.xpm",
			&game->width, &game->height);
	game->exit_img2 = mlx_xpm_file_to_image(game->mlx, "images/door.xpm",
			&game->width, &game->height);
	if (!game->wall_img || !game->back_img || !game->player_img
		|| !game->img1_img || !game->exit_img || !game->exit_img2)
	{
		ft_printf("%s\n", "Error");
		exit(0);
	}
}

static void	size_window(t_stack *game)
{
	int	i;

	game->map_width = ft_strlen(game->map[0]) * 64;
	i = 0;
	while (game->map[i])
		i++;
	game->map_height = i * 64;
}

void	create_window(t_stack *game)
{
	game->mlx = mlx_init();
	size_window(game);
	game->win = mlx_new_window(game->mlx, game->map_width, game->map_height,
			"Window Shopper");
	game->moves = 0;
	game->endgame = 0;
	put_images(game);
	map_draw(game);
}
