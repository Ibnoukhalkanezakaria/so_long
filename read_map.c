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

char	**read_map(char *path)
{
	int		fd;
	char	*line;
	char	*empty_string;
	char	**map;
	char	*get_empty_s;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	empty_string = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		get_empty_s = empty_string;
		empty_string = ft_strjoin(get_empty_s, line);
		free(line);
	}
	map = ft_split(empty_string, '\n');
	free(empty_string);
	return (map);
}
