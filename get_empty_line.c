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

int	get_empty_line(char *path, int length)
{
	(void)length;
	int		fd;
	char	*line;
	int		count;
    
	count = 1;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);

	while ((line = get_next_line(fd)))
	{
		// if(ft_strlen(line) < length || ft_strlen(line) == 1)
		// 	return 0;
		// if(ft_strlen(line) == 1)
		// {
		// 	count++;
		// }
		// if(line == "\0")
		// {
			printf("%s", line);
		// }
	}
	return count;
}
