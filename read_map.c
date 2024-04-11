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

char**    read_map(char *path, t_stack *game)
{
    int fd;
    char *line;
    char *empty_string;
    char **map;
    char *get_empty_s;
    int count;
    int j;

    fd = open(path, O_RDONLY);
    
    empty_string = ft_strdup("");
    count = 0;
    while (1)
    {
        line = get_next_line(fd);
        if(!line)
            break;
        get_empty_s = empty_string;
        empty_string = ft_strjoin(get_empty_s, line);
        count++;
    }
    game->height = count*16;
    map = ft_split(empty_string, '\n');
    j = 0;
    while (map[0][j++])
    game->width = j*16;
    return map;
}
