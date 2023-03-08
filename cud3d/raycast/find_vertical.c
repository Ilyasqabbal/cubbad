/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_vertical.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqabbal <iqabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 00:45:35 by iqabbal           #+#    #+#             */
/*   Updated: 2023/03/08 07:20:27 by iqabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Cub3d.h"

double correction_anglev(double ray_angle)
{
    if(ray_angle < 2 * M_PI && ray_angle> 1.5 * M_PI)
        return( 2 * M_PI - ray_angle);
    else if(ray_angle < 1.5 * M_PI && ray_angle> M_PI)
        return(ray_angle - M_PI);
    else if(ray_angle <  M_PI && ray_angle> M_PI_2)
        return(M_PI - ray_angle);
    else if(ray_angle <  M_PI_2 && ray_angle> 0)
        return(ray_angle);
    return(ray_angle);
    
}

void first_intersection_vertical(t_data *data,t_first *first,double ray_angle)
{
    first->v_x= floor(data->player->x / 40) *  40;
    if(is_facing_left(to_degree(ray_angle)) == false)
        first->v_x +=data->size;
    // printf("firsst h%f\n",first->v_x); 
    // if(to_degree(ray_angle) == 180)
    //     first->h_x = 40;
    // else if(to_degree(ray_angle) == 0)
    //     first->h_x = (data->width * 40) - 40;
    // else
    ray_angle = correction_anglev(ray_angle);
    first->v_y = data->player->y + (( -data->player->x + first->v_x )*tan(ray_angle));
    // printf("firsst xxxx:%f\n",first->v_y); 
      ///90= inf //270 inf     
}

double vertical_intersection(t_data *data, double ray_angle)
{
    t_first first;
    int		check;

	check = 0;
    ray_angle = normalize_angle(ray_angle);
    first_intersection_vertical(data,&first,ray_angle);
    int xstep = data->size;
    if (!(ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI))
	{
		xstep *=-1;
		check = -1;
	}
    double ystep = data->size*tan(ray_angle);
    if (!(ray_angle > 0 && ray_angle < M_PI) && ystep > 0)
		ystep *= -1;
	if ((ray_angle > 0 && ray_angle < M_PI) && ystep < 0)
		ystep *= -1;
    double v_x = first.v_x;
    double v_y = first.v_y;
    while(check_wall(data,v_x,v_y,check,1))
    {
        v_x += xstep;
        v_y += ystep;
    }
    first.v_x = v_x;
    first.v_y = v_y;
    printf("angle is : %f\n",to_degree(ray_angle));
    printf("first x vertical : %f\n",fabs(v_x/data->size));
    printf("first y vertical : %f\n",fabs(v_y/data->size));
    printf("The distance vert is :  %f\n",return_distance(data->player->x,first.v_x,data->player->y,first.v_y));
    return(return_distance(data->player->x,first.v_x,data->player->y,first.v_y));
}