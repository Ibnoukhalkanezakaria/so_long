/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:58:10 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/03/19 23:41:35 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_empty_line(char *path)
{
	int		fd;
	char	*line;
	int		count;
	int		empty;
	bool	check;
	int		result;
	int		tmp;

	empty = 0;
	check = true;
	result = 0;
	count = 1;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	while ((line = get_next_line(fd)))
	{
		if (check)
		{
			result = ft_strlen(line);
			check = false;
		}
		tmp = ft_strlen(line);
		empty = tmp;
		tmp = empty;
	}
	if (result == empty)
		return (0);
	return (1);
}
