/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqabbal <iqabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:17:38 by iqabbal           #+#    #+#             */
/*   Updated: 2023/03/08 01:27:45 by iqabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/move.h"

#define CHECK 40
int check_next_position(t_data *data,int flag)
{
    t_player    *player;
    int         x;
    int         y;
    
    x = 0;
    y = 0;
    player = data->player;
    if(flag == MOVE_RIGHT)
    {
          x = ((*player).x - (*player).speed * cos(player->angle - (M_PI/2))) / CHECK;
          y = ((*player).y - (*player).speed * sin(player->angle - (M_PI/2))) / CHECK;
         
    }
    else if(flag == MOVE_LEFT )
    {
          x = ((*player).x + (*player).speed * cos(player->angle - (M_PI/2))) / CHECK;
          y = ((*player).y + (*player).speed * sin(player->angle - (M_PI/2))) / CHECK;
    }
    else if(flag == MOVE_UP)
    {
         x = ((*player).x + (*player).speed * cos(player->angle)) / CHECK ;
         y = ((*player).y + (*player).speed * sin(player->angle)) / CHECK;
    }
    else if(flag == MOVE_DOWN)
    {
         x = ((*player).x - (*player).speed * cos(player->angle)) / CHECK ;
         y = ((*player).y - (*player).speed * sin(player->angle)) / CHECK;
    }
    if(data->map[y][x] == '0')
         return(1);
    else
         return(0);
}

void move_down(t_data *data)
{
    t_player *player;
    player = data->player;
   if(check_next_position(data,MOVE_DOWN))
   {
        (*player).y = (*player).y - (*player).speed * sin(player->angle);
        (*player).x = (*player).x - (*player).speed * cos(player->angle);
   }
}
