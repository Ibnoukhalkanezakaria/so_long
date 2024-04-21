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

#include "../so_long.h"

int get_length(t_stack *game)
{
    int i;

    i = 0;
    while (game->map[i])
        i++;
    return i;
}

int how_much_ones(char *line)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (line[i])
    {
        if(line[i] == '1')
            count++;
        i++;
    }
    return count;
}

int f1(t_stack *game)
{
    int i;
    int count;
    int length_of_the_last_line = get_length(game);

    i = 0;
    count = 0;
    char *p = game->map[0];
    while (i < length_of_the_last_line)
    {
        if(game->map[i][0] == '1')
            count++;
        i++;
    }
    
    return count;
}

int f2(t_stack *game)
{
    int i;
    int count;
    int length_of_the_last_line = get_length(game);

    i = 0;
    count = 0;
    int size = ft_strlen(game->map[0]) - 1;
    char *p = game->map[0];
    while (i < length_of_the_last_line)
    {
        if(game->map[i][size] == '1')
            count++;
        i++;
    }
    
    return count;
}

int    map_checker_two(t_stack *game)
{
    int get_count_f1 = f1(game);
    int get_count_f2 = f2(game);
    int length_of_the_last_line = get_length(game);
    int get_first_line = how_much_ones(game->map[0]);
    int get_last_line = how_much_ones(game->map[length_of_the_last_line - 1]);

    // printf("get_count_f1: %d\n", get_count_f1);
    // printf("get_count_f2: %d\n", get_count_f2);
    // printf("get_first_line: %d\n", get_first_line);
    // printf("get_second_line: %d\n", get_first_line);
    if((get_count_f1 == get_count_f2) && (get_first_line == get_last_line))
    {
        // ft_printf("%s\n", "hakalbaroud");
        return 1;
    }
    else
    {
        // ft_printf("%s\n", "machich 7aga tigi kida");
        return 0;
    }
}
