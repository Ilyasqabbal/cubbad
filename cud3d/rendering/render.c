/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqabbal <iqabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:53:54 by iqabbal           #+#    #+#             */
/*   Updated: 2023/03/11 05:51:51 by iqabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

void	ft_wall(t_data *data, int i, double top, double bottom, t_rays *r)
{
    int n;
    int m;
    n = 0;
    double ilyass = top;
    while(top <= bottom)
    {
        m = -1;
        
        while(++m < (bottom - top)/40)
        {
            if(data->cor == 2)
                my_mlx_pixel_put(data, i, (int)top + m, *(data->img1.add_img + (int)(n*40 + fmod(r->x, 40)) ));
            else if(data->cor == 1)
                my_mlx_pixel_put(data, i, (int)top + m, *(data->img1.add_img + (int)(n*40 + fmod(r->y, 40)) ));
            
        }
        n++;
        top += (bottom - ilyass)/ 40;
    }
}
void render(t_data *data,t_rays *r)
{
    
    t_render *render;
    render = init_struct_render(data,r);
    double top;
    double bottom;
    int i = 0;
    
     top = (data->height_window / 2) - ((render->wall_stripe_height) / 2);
     bottom =  top + render->wall_stripe_height - 1;
        while (i < top )
        {
            my_mlx_pixel_put(data,r->columid, i,0xFFFFFFF);
            i++;
        }
        // while (i < top + render->wall_stripe_height )
        // {
        //     my_mlx_pixel_put(data,r->columid,i,0x00000000);
        //     i++;
        // }
        
        ft_wall(data, r->columid, top, bottom, r);
        // printf("bf %d\n",i);
        // i = bottom - 1;
        // printf("af %d\n",i);
        while (bottom < data->height_window )
        {
            my_mlx_pixel_put(data,r->columid,bottom,0xFFFFFFF);
            bottom++;
        }
      
    
    

}