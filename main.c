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
	t_stack box;
	int empty_line = 0;
	int length = 0;
	int newlength = 0;

	if (ac == 2)
	{
		game.map = read_map(av[1]);
		length = ft_strlen(game.map[0]) - 1; 
		// empty_line = get_empty_line(av[1], length);
		// newlength = get_newlength(av[1]);
		
		// ft_printf("%d\n", empty_line);		
		if((map_checker(&game)) && (map_checker_two(&game) && (map_checker_three(&game))))
		{
			// create_window(&game);
			// play(&game);
			// mlx_loop(game.mlx);
			ft_printf("%s\n", "hakalbaroud");		
		}
		else
			ft_printf("%s\n", "mafich 7aga tigi kida");
	}
	else
		ft_printf("%s\n", "Error");
	return (0);
}
