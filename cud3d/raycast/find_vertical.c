/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_vertical.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqabbal <iqabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 00:45:35 by iqabbal           #+#    #+#             */
/*   Updated: 2023/03/09 06:11:37 by iqabbal          ###   ########.fr       */
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
        return(ray_angle + M_PI);
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
    /*
    -data->player->x + first->v_x
    +data->player->x - first->v_x*/
    
    ray_angle = correction_anglev(ray_angle);
    //  if(is_facing_up(ray_angle))
    //  {
    //      data->player->x *= -1;
    //      if(first->v_x > 0)
    //         first->v_x *= -1;  
    //  }
    first->v_y = data->player->y + ((-data->player->x + first->v_x )*tan(ray_angle));
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
    int xstep = 40;
    if (!(ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI))
	{
        xstep *= -1;
        check = -1;
	}
    ray_angle = correction_anglev(ray_angle);
    double ystep = xstep * tan((ray_angle));
    if (!(ray_angle > 0 && ray_angle < M_PI) && ystep > 0)
		ystep *= 1;
	if ((ray_angle > 0 && ray_angle < M_PI) && ystep < 0)
		ystep *= 1;
    double v_x = first.v_x;
    double v_y = first.v_y;
    // if(check_wall(data,v_x,v_y))
    //         return(return_distance(data->player->x,first.v_x,data->player->y,first.v_y));
    int i = 1;
    while(i)
    {
        check_wall(data,&first,check,0);
        v_x += xstep;
        v_y += ystep;
        // if(check_wall(data,v_x,v_y))
        //     break;
        i--;
        // printf(" x vertical after increment : %f\n",fabs(v_x/data->size));
        // printf(" y vertical after increment: %f\n",fabs(v_y/data->size));
    } 
    // first.v_x = v_x;
    // first.v_y = v_y;
    // printf("angle is : %f\n",to_degree(ray_angle));
    // printf("first x vertical : %f\n",fabs(v_x/data->size));
    // printf("first y vertical : %f\n",fabs(v_y/data->size));
    // printf("The distance vert is :  %f\n",return_distance(data->player->x,first.v_x,data->player->y,first.v_y));
    return(return_distance(data->player->x,first.v_x,data->player->y,first.v_y));
}