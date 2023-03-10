/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqabbal <iqabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:17:51 by iqabbal           #+#    #+#             */
/*   Updated: 2023/03/10 02:41:40 by iqabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/move.h"

void move_left(t_data *data)
{
    if(check_next_position(data,MOVE_LEFT))
    {
       data->player->x =  data->player->x + data->player->speed * cos(data->player->angle - (M_PI/2));
       data->player->y =  data->player->y + data->player->speed * sin(data->player->angle - (M_PI/2));
    }
}