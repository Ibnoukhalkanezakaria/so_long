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

int	main(int ac, char **av)
{
	t_stack	game;
	int		empty_line;
	if (ac == 2)
	{
		game.map = read_map(av[1]);
		empty_line = get_empty_line(av[1]);
		map_checker_four(&game);
		// if ((map_checker(&game)) && (map_checker_two(&game)
		// 		&& (map_checker_three(&game)) && (empty_line)))
		// {
		// 	create_window(&game);
		// 	play(&game);
		// 	mlx_loop(game.mlx);
		// }
		// else
		// 	ft_printf("%s\n", "Map is invalid!");
	}
	else
		ft_printf("%s\n", "Error");
	return (0);
}
