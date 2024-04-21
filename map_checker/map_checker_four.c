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

void get_player_cord(t_stack *game)
{
    int i = 0;
    int j = 0;
    while(game->map[i] != NULL)
    {
        j = 0;
        while(game->map[i][j] != '\n' && game->map[i][j] != '\0')
        {
            if (game->map[i][j] == 'P')
            {
                game->x_play = i;
                game->y_play = j;
            }
            if (game->map[i][j] == 'C')
                game->total_collect += 1;
            j++;
        }
        i++;
    }
}

void fill_visited(t_stack *game)
{
    int i = 0;
    int j = 0;
    game->visited = malloc(400 * sizeof(int *));
    while (i < 400)
    {
        j = 0;
        game->visited[i] = malloc(500 * sizeof(int));
        while (j < 500)
        {
            game->visited[i][j] = 0;
            j++;
        }
        i++;
    }
}

void flood_fill(t_stack *game, int x, int y)
{
    if ((game->map[x][y] == '0' || game->map[x][y] == 'C') && !game->visited) 
    {
        game->visited[x][y] = 1;
        if (game->map[x][y] == 'C')
            game->collect_found += 1;
        flood_fill(game, x - 1, y);
        flood_fill(game, x + 1, y);
        flood_fill(game, x, y - 1);
        flood_fill(game, x, y + 1);
    }
}

int    map_checker_four(t_stack *game)
{
    game->collect_found = 0;
    game->total_collect = 0;
    get_player_cord(game);
    fill_visited(game);
    flood_fill(game, game->x_play, game->y_play);
    if (game->collect_found != game->total_collect)
    {
        printf("Map Is invalid\n");
    }
    return 0;
}
