/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqabbal <iqabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:53:54 by iqabbal           #+#    #+#             */
/*   Updated: 2023/03/10 09:50:24 by iqabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

    // int widht;
    // int height;
    // double distance_proj_plan;
    // double wall_stripe_height;
    // double ray_distance;
    // int size;

// void	my_mlx_pixel_put(t_data *cor, int i, int j)
// {
// 	char	*dst;

// 	if (i > 0 && j > 0 && W > i && H > j)
// 	{
// 		dst = cor->mlx.addr + (j * cor->mlx.line_length + \
// 		i * (cor->mlx.bits_per_pixel / 8));
// 		*(unsigned int *)dst = cor->color;
// 	}
// }









void render(t_data *data,t_rays *r)
{
    
    t_render *render;
    //double tmp = r->columid;
    //r->columid *= cos(r->ray_angle - data->player->angle);
    render = init_struct_render(data,r);
    //r->columid = tmp;
    double top;
    double bottom;
    int i = 0;
    
     top = (data->height_window / 2) - ((render->wall_stripe_height) / 2);
     bottom = (render->wall_stripe_height) + top;
        while (i < top  )
        {
            mlx_pixel_put(data->mlx,data->mlx_win,r->columid,i,0x00FFFFFF);
            i++;
        }
        while (i < top + render->wall_stripe_height )
        {
            mlx_pixel_put(data->mlx,data->mlx_win,r->columid,i,0x0000FFFF);
            i++;
        }
        while (i < data->height_window )
        {
            mlx_pixel_put(data->mlx,data->mlx_win,r->columid,i,0x000000FF);
            i++;
        }
    printf("c");
    
    

}