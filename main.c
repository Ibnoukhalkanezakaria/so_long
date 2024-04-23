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

#include "so_long.h"

int sum_c(t_stack *game)
{
    int i = 0;
    int j;
    int count = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            if(game->map[i][j] == 'C')
                count++;
            j++;
        }
        i++;
    }
    return count;
}

int	main(int ac, char **av)
{
	t_stack	game;
	int		empty_line;
	int	csize;
	int	i;

	if (ac == 2)
	{
		game.map = read_map(av[1]);
		csize = sum_c(&game);
		empty_line = get_empty_line(av[1]);
		game.coins = stack(&game, sum_c(&game));
		map_checker_four(&game, game.x_play, game.y_play , csize);
		// i = 0;
		// while (i < csize)
		// {
		// 	ft_printf("\n - N%i\n - position [%i,%i]\n - claimed %s\n", i, game.coins->x, game.coins->y, game.coins->claimed ? "yes" : "no");
		// 	i++;
		// }
		
		// if ((map_checker(&game)) && (map_checker_two(&game)
		// 		&& (map_checker_three(&game)) && (empty_line)))
		// {
			// create_window(&game);
			// play(&game);
			// get_x_y(&game);
			// mlx_loop(game.mlx);
		// }
		// else
		// 	ft_printf("%s\n", "Map is invalid!");
	}
	else
		ft_printf("%s\n", "Error");
	return (0);
}
