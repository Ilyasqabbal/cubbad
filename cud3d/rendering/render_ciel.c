/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ciel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqabbal <iqabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:43:51 by iqabbal           #+#    #+#             */
/*   Updated: 2023/03/10 08:34:31 by iqabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"



void render_ciel(int top,t_data *data,double columid,int color){

    while(top >= 0)
    {
        mlx_pixel_put(data->mlx,data->mlx_win,columid,top,color);
        top--;
    }
     //put_img_to_window(data);
}