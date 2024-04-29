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

int fill(char *empty_s, int num, int check)
{
    int i;
    int count;

    count = 0;
    i = 0;
    while (empty_s[i])
    {
        if(empty_s[i] == '\n')
            count++;
        i++;
    }

    if(count > num || check)
        return 0;
    return 1;
}

int get_empty(char *path)
{
    int fd;
    char *line;
    char *empty_s = NULL;
    char *string = NULL;
    int i = 0;
    int check = 0;
    
    fd = open(path, O_RDONLY);
    if (fd == -1)
        return -1;
    
    while ((line = get_next_line(fd)))
    {
        if(ft_strlen(line) <= 1)
            check = 1;
        char *temp = ft_strjoin(empty_s, line); 
        empty_s = temp; 
        i++;
    }
    return fill(empty_s, i - 1, check);
}
