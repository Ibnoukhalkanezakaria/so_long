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

	if (ac == 2)
	{
		game.map = read_map(av[1]);
		map_checker_three(&game);
		// if((map_checker(&game)) && (map_checker_two(&game)))
		// {
		// 	// create_window(&game);
		// 	// play(&game);
		// 	// mlx_loop(game.mlx);
		// 	ft_printf("%s\n", "hakalbaroud");		
		// }
		// if(map_checker_three(&game))
		// {
		// 	ft_printf("%s\n", "hakalbaroud");
		// }
		// else
		// 	ft_printf("%s\n", "machich 7aga tigi kida");
	}
	else
		ft_printf("%s\n", "Error");
	return (0);
}
