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

// int sum_c(t_stack *game)
// {
//     int i = 0;
//     int j;
//     int count = 0;
//     while (game->map[i])
//     {
//         j = 0;
//         while (game->map[i][j])
//         {
//             if(game->map[i][j] == 'C')
//                 count++;
//             j++;
//         }
//         i++;
//     }
//     return count;
// }

// int	semu_x(t_stack	*game)
// {
// 	int i = 0;
// 	int j;
// 	int x = 0;
// 	int y = 0;
// 	while (game->map[i])
// 	{
// 		j = 0;
// 		while (game->map[i][j])
// 		{
// 			if(game->map[i][j] == 'P')
// 				x = i;
// 			j++;
// 		}
// 		i++;
// 	}
// 	return x;
// }

// int	semu_y(t_stack	*game)
// {
// 	int i = 0;
// 	int j;
// 	int x = 0;
// 	int y = 0;
// 	while (game->map[i])
// 	{
// 		j = 0;
// 		while (game->map[i][j])
// 		{
// 			if(game->map[i][j] == 'P')
// 				y = j;
// 			j++;
// 		}
// 		i++;
// 	}
// 	return y;
// }

// int **arr_visited(int max_h, int max_w)
// {
//     int **arr = (int **)malloc(max_h * sizeof(int *));
//     int i = 0;
//     int j;
//     while (i < max_h) {
//         arr[i] = (int *)malloc(max_w * sizeof(int));
//         j = 0;
//         while (j < max_w) {
//             arr[i][j] = 0;
//             j++;
//         }
//         i++;
//     }

//     return arr;
// }

int	main(int ac, char **av)
{
	t_stack	game;
	int		empty_line;
	int	csize;
	int	i;
	int x;
	int y;
	bool count = false;

	if (ac == 2)
	{
		game.map = read_map(av[1]);
		// csize = sum_c(&game);
		// empty_line = get_empty_line(av[1]);
		// x = semu_x(&game);
		// y = semu_y(&game);
		// game.collect_found = 0;
    	// game.visited = arr_visited(7, 21);
		// map_checker_four(&game, x, y);
		// if ((map_checker(&game)) && (map_checker_two(&game)
		// 		&& (map_checker_three(&game)) && (empty_line) && (game.collect_found == csize)))
		// {
			create_window(&game);
			// play(&game);
			mlx_loop(game.mlx);
		// }
		// else
		// {
		// 	ft_printf("%s\n", "Map is invalid!");
		// 	exit(0);
		// }

	}
	else
		ft_printf("%s\n", "Error");
	return (0);
}
