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

int	ft_s(char *string, int j)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (string[i])
	{
		if (string[i] == '\n')
			count++;
		i++;
	}
	if (count > (j - 1))
		return (0);
	return (1);
}

int	get_empty(char *path)
{
	int		fd;
	char	*line;
	char	*empty_s;
	char	*string;
	int		i;

	fd = open(path, O_RDONLY);
	i = 0;
	empty_s = ft_strdup("");
	while ((line = get_next_line(fd)))
	{
		string = ft_strjoin(empty_s, line);
		empty_s = string;
		i++;
	}
	return (ft_s(string, i));
}
