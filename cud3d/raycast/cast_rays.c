/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqabbal <iqabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 00:45:28 by iqabbal           #+#    #+#             */
/*   Updated: 2023/03/12 04:50:31 by iqabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Cub3d.h"

double to_degree(double r)
{
    return(r * (180/M_PI));
}

double to_radian(double d)
{
    return(d * (M_PI / 180));
}

void cast_All_rays(t_data *data)
{
    t_rays r;
    r.number_rays  = data->width_window;
    r.fov = M_PI / 3;
    r.ray_angle = data->player->angle - r.fov/2;
    int i = 0;
    double hz;
    double vrt;
    // mlx_clear_window(data->mlx,data->mlx_win);
    create_img(data);
   while(i < r.number_rays )
   {

        hz = horizontal_intersection(data,r.ray_angle);
        vrt = vertical_intersection(data,r.ray_angle);
        if(hz > vrt)
        {
                r.ray_distance = vrt;
                r.x = data->v_ray_dis_x;
                r.y = data->v_ray_dis_y;
                data->cor = 1;
                //drawRay(data,data->player->x ,data->player->y ,data->player->x ,data->player->y ,r.ray_angle,r.ray_distance,0x0000FF);
        }
        else
        {
            data->cor = 2;
            r.ray_distance = hz;
            r.x = data->h_ray_dis_x;
            r.y = data->h_ray_dis_y;    
            //drawRay(data,data->player->x ,data->player->y ,data->player->x ,data->player->y,r.ray_angle,r.ray_distance,0x0000FF);
        }
        r.columid = i;
        render(data,&r);
        r.ray_angle += r.fov/r.number_rays ;
        i++;
  }
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img_window, 0, 0);
	mlx_destroy_image (data->mlx, data->img.img_window);

}

//90= inf horizental
//270 inf horizental
 //0 = 0 vertical
 //180  =0 vertical 



        // if(to_degree(r.ray_angle) == 90 || to_degree(r.ray_angle) == 180 || to_degree(r.ray_angle) == 270 || to_degree(r.ray_angle) == 0 )
        // {);
        //  printf("The distance is : %f",r.ray_distance);}




