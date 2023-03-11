/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_rendring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqabbal <iqabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 03:09:14 by iqabbal           #+#    #+#             */
/*   Updated: 2023/03/11 04:17:23 by iqabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"



void create_img(t_data *data)
{
    data->img.img_window =  mlx_new_image(data->mlx,data->width_window,data->height_window);
    data->img.add_img = mlx_get_data_addr(data->img.img_window,&data->img.bit_pixel, &data->img.line_len, &data->img.endian);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*destination;
	if ((x >= 0 && x <  data->width_window) && (y >= 0 && y < data->height_window))
	{
		destination = (data->img.add_img + (y * data->img.line_len \
				+x * (data->img.bit_pixel / 8)));
		*(int *)destination = color;
	}
}