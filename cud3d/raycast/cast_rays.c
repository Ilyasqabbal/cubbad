/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqabbal <iqabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 00:45:28 by iqabbal           #+#    #+#             */
/*   Updated: 2023/03/08 03:03:05 by iqabbal          ###   ########.fr       */
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
    r.number_rays  = 60;
    r.fov = 60;
    //data->player->angle = 180;
    r.ray_angle = data->player->angle - to_radian(r.fov/2);
    int i = 0;
   while(i < r.number_rays )
   {
          double hz = horizontal_intersection(data,r.ray_angle);
          double vrt = vertical_intersection(data,r.ray_angle);
             if(hz > vrt)
                 r.ray_distance = vrt;
             else
                r.ray_distance = hz;      
            // printf("distance for printting is : %f\n",r.ray_distance);
            drawRay(data,data->player->x,data->player->y,data->player->x,data->player->y,r.ray_angle,r.ray_distance,0x0000FF);
            r.columid = i;
            //render(data,&r);
            r.ray_angle += to_radian(r.fov)/r.number_rays ;
            i++;
  }

}

//90= inf
//270 inf
 //0 = 0
 //180  =0 
 //360 = 0




