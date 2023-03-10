/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqabbal <iqabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:17:58 by iqabbal           #+#    #+#             */
/*   Updated: 2023/03/10 02:41:24 by iqabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/move.h"

void move_up(t_data *data)
{
    if(check_next_position(data,MOVE_UP))
    {
        data->player->y += data->player->speed * sin(data->player->angle);
        data->player->x += data->player->speed * cos(data->player->angle);
   }
}