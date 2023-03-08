/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqabbal <iqabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:18:51 by iqabbal           #+#    #+#             */
/*   Updated: 2023/03/04 09:04:59 by iqabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/move.h"
#include "../header/Cub3d.h"


int all_position(char **map, int x, int y)
{
    if(map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E' ||map[y][x] == 'W' )
            return(1);
    return(0);
}

int x_player(char **map)
{
    int x;
    int y;

    x = 0;
    y = 0;
   // printf("hello world\n");
    while(map[y])
    {
        x = 0;
        while(map[y][x])
        {
         if( all_position(map, x, y))
            return(x);
         x++;   
        }
        y++;
    }
    return(-1);
    
}

int  y_player(char **map)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while(map[y])
    {
        x = 0;
        while(map[y][x])
        {
            if( all_position(map, x, y))
                return(y);
         x++;   
        }
        y++;
    }
    return(-1);
}