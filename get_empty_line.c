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

int get_empty_line(char *path) {
    int fd;
    char *line;
    int empty = 0;
    bool check = true;
    int result = 0;
    int tmp;

    fd = open(path, O_RDONLY);
    if (fd == -1)
        return 0;

    while ((line = get_next_line(fd)))
	{
        if (check) {
            result = ft_strlen(line);
            check = false;
        }
        tmp = ft_strlen(line);
        empty = tmp;
        // free(line);
    }
    // close(fd);

    if (result == empty)
        return 0;
    return 1;
}
