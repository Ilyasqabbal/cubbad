/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqabbal <iqabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:17:38 by iqabbal           #+#    #+#             */
/*   Updated: 2023/03/10 02:42:14 by iqabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/move.h"

#define CHECK 40
int check_next_position(t_data *data,int flag)
{
    int         x;
    int         y;
    
    x = 0;
    y = 0;
    if(flag == MOVE_RIGHT)
    {
          x = (data->player->x - data->player->speed * cos(data->player->angle - (M_PI/2))) / CHECK;
          y = (data->player->y - data->player->speed * sin(data->player->angle - (M_PI/2))) / CHECK;
         
    }
    else if(flag == MOVE_LEFT )
    {
          x = (data->player->x + data->player->speed * cos(data->player->angle - (M_PI/2))) / CHECK;
          y = (data->player->y + data->player->speed * sin(data->player->angle - (M_PI/2))) / CHECK;
    }
    else if(flag == MOVE_UP)
    {
         x = (data->player->x + data->player->speed * cos(data->player->angle)) / CHECK ;
         y = (data->player->y + data->player->speed * sin(data->player->angle)) / CHECK;
    }
    else if(flag == MOVE_DOWN)
    {
         x = (data->player->x - data->player->speed * cos(data->player->angle)) / CHECK ;
         y = (data->player->y - data->player->speed * sin(data->player->angle)) / CHECK;
    }
    if(data->map[y][x] == '0')
         return(1);
    else
         return(0);
}

void move_down(t_data *data)
{
   if(check_next_position(data,MOVE_DOWN))
   {
        data->player->y = data->player->y - data->player->speed * sin(data->player->angle);
        data->player->x = data->player->x - data->player->speed * cos(data->player->angle);
   }
}
