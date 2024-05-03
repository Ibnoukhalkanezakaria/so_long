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

static int	**arr_visited(int max_h, int max_w)
{
	int	**arr;
	int	i;
	int	j;

	arr = (int **)malloc(max_h * sizeof(int *));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < max_h)
	{
		arr[i] = (int *)malloc(max_w * sizeof(int));
		if (!arr[i])
			return (NULL);
		j = 0;
		while (j < max_w)
			arr[i][j++] = 0;
		i++;
	}
	return (arr);
}

int	checking(t_stack *game, char *av)
{
	int	i;

	i = ft_strlen(av) - 1;
	if ((!(av[i] == 'r' && av[i - 1] == 'e' && av[i - 2] == 'b'
				&& av[i - 3] == '.')) || !(game->map)
		|| (ft_strlen(game->map[0])) < 1)
	{
		ft_printf("%s\n", "Error\nMap is invalid!");
		exit_game_three(game);
	}
	return (1);
}

static void	call(t_stack *game, int check, int count)
{
	if (check && count)
	{
		create_window(game);
		play(game);
		mlx_loop(game->mlx);
	}
	else
	{
		ft_printf("%s\n", "Error\nMap is invalid!");
		exit_game_two(game);
	}
}

int	main(int ac, char **av)
{
	t_stack	game;
	int		check;
	int		count;
	int		result;

	ft_memset((void *)&game, 0, sizeof(t_stack));
	result = 0;
	if (ac == 2)
	{
		game.map = read_map(av[1]);
		count = checking(&game, av[1]);
		if ((count))
			result = get_empty(av[1]);
		delete (&game);
		game.visited = arr_visited(game.maph, game.mapw);
		check = check_all(&game, game.xx, game.yy);
		call(&game, check, result);
	}
	else
		ft_printf("%s\n", "Error");
	return (0);
}
