/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zibnoukh <zibnoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:56:18 by zibnoukh          #+#    #+#             */
/*   Updated: 2024/03/19 23:49:32 by zibnoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int sum_c(t_stack *game)
// {
//     int i = 0;
//     int j;
//     int count = 0;
//     while (game->map[i])
//     {
//         j = 0;
//         while (game->map[i][j])
//         {
//             if(game->map[i][j] == 'C')
//                 count++;
//             j++;
//         }
//         i++;
//     }
//     return count;
// }



int** f()
{
    char* map = "000000000000000000\n"
                "000000000000000000\n"
                "000000000000000000\n"
                "000000000000000000\n"
                "000000000000000000\n"
                "000000000000000000\n"
                "000000000000000000";

    int **arr = (int **)malloc(7 * sizeof(int *));
    int i = 0;
    while (i < 7) {
        arr[i] = (int *)malloc(21 * sizeof(int));
        int j = 0;
        while (j < 21) {
            arr[i][j] = 0;
            j++;
        }
        i++;
    }

    return arr;
}


