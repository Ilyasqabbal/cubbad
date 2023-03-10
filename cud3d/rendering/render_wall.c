/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqabbal <iqabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:43:47 by iqabbal           #+#    #+#             */
/*   Updated: 2023/03/10 08:39:04 by iqabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

void render_wall(int top,int bottom,t_data *data,double columid,int color)
{
    //top++;
    (void)bottom;
    (void)columid;
    while(top <= 500)
    {
        mlx_pixel_put(data->mlx, data->mlx_win,1  ,top ,color);
        //dsquare(data,columid * 40,bottom* 40,color,40);
        top++;
    }
}