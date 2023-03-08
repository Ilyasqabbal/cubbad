/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqabbal <iqabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:17:58 by iqabbal           #+#    #+#             */
/*   Updated: 2023/03/02 22:23:17 by iqabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/move.h"

void move_up(t_data *data)
{
    t_player *player;
    player = data->player;
    if(check_next_position(data,MOVE_UP))
    {
        (*player).y += (*player).speed * sin(player->angle);
        (*player).x += (*player).speed * cos(player->angle);
   }
}