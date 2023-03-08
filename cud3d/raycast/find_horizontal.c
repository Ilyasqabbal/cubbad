/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_horizontal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqabbal <iqabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 00:45:31 by iqabbal           #+#    #+#             */
/*   Updated: 2023/03/08 07:20:15 by iqabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Cub3d.h"


//0 //180

double correction_angele(double ray_angle)
{
    if(ray_angle < 2 * M_PI && ray_angle> 1.5 * M_PI)
        return(ray_angle - 1.5 * M_PI);
    else if(ray_angle < 1.5 * M_PI && ray_angle> M_PI)
        return(-ray_angle + 1.5 * M_PI);
    else if(ray_angle <  M_PI && ray_angle> M_PI_2)
        return(ray_angle - M_PI_2);
    else if(ray_angle <  M_PI_2 && ray_angle> 0)
        return(-ray_angle + M_PI_2);
    return(ray_angle);
    
}

void first_intersection_horizontal(t_data *data,t_first *first,double ray_angle)
{
    first->h_y= floor(data->player->y / 40) *  40;
    if(is_facing_up(to_degree(ray_angle)) == false)
        first->h_y +=data->size;
    // printf("firsst h%f\n",first->h_y); 
    // if(to_degree(ray_angle) == 180)
    //     first->h_x = 40;
    // else if(to_degree(ray_angle) == 0)
    //     first->h_x = (data->width * 40) - 40;
    // else
    ray_angle = correction_angele(ray_angle);
    first->h_x = data->player->x + (( -data->player->y + first->h_y )*tan(ray_angle));
    // printf("firsst xxxx:%f\n",first->h_x); 
      ///90= inf //270 inf     
}


 
double horizontal_intersection(t_data *data, double ray_angle)
{
    t_first first;
    int check = 0;
    ray_angle = normalize_angle(ray_angle);
    first_intersection_horizontal(data,&first,ray_angle);
    int ystep = 40;
    if (!(ray_angle > 0 && ray_angle < M_PI))
	{
        ystep *=-1;
        check = -1;
    }
    double xstep = data->size/tan(correction_angele(ray_angle));
    if ((ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI) && xstep < 0)
		xstep *= -1;
	if (!(ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI) && xstep > 0)
		xstep *= 1;
    double h_x = first.h_x;
    double h_y = first.h_y;
   while(1)
   {
    
    printf("first x horizental : %f\n",(h_x/data->size));
    printf("first y horizental : %f\n",(h_y/data->size));
       if(check_wall(data,h_x,h_y,check,1) == 0)
           break;
        h_x += xstep;
        h_y += ystep;
   }
    first.h_x = h_x;
    first.h_y = h_y;
    // printf("The distance horiz is :  %f\n",return_distance(data->player->x,first.h_x,data->player->y,first.h_y));
    return(return_distance(data->player->x,first.h_x,data->player->y,first.h_y));
}
