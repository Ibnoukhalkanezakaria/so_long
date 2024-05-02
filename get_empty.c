/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_empty.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:58:10 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/03/19 23:41:35 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fill(char *empty_s, int num)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (empty_s[i])
	{
		if (empty_s[i] == '\n')
			count++;
		i++;
	}
	if (count > num)
		return (0);
	return (1);
}

int	vim(char *empty_s, int i)
{
	int	r;

	r = fill(empty_s, i - 1);
	free(empty_s);
	return (r);
}

int	one(char *path)
{
	int		fd;
	char	*line;
	char	*empty_s;
	char	*temp;
	int		i;

	i = 0;
	empty_s = NULL;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = ft_strjoin(empty_s, line);
		empty_s = temp;
		free(line);
		i++;
	}
	return (vim(empty_s, i));
}

int	two(char *path)
{
	int		fd;
	char	*line;
	int		check;

	check = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strlen(line) <= 1)
			check = 1;
		free(line);
	}
	if (check)
		return (0);
	return (1);
}

int	get_empty(char *path)
{
	int	val_one;
	int	val_two;

	val_one = one(path);
	val_two = two(path);
	if (val_one && val_two)
		return (1);
	return (0);
}
