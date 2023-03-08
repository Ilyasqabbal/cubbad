/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_reight.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqabbal <iqabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:17:55 by iqabbal           #+#    #+#             */
/*   Updated: 2023/03/02 22:23:23 by iqabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/move.h"

void move_reight(t_data *data)
{
    t_player *player;
    player = data->player;
    if(check_next_position(data,MOVE_RIGHT))
    {
        (*player).x -= (*player).speed * cos(player->angle - (M_PI/2));
        (*player).y -= (*player).speed * sin(player->angle - (M_PI/2));
    }
}
