/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_horizontal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqabbal <iqabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 00:45:31 by iqabbal           #+#    #+#             */
/*   Updated: 2023/03/10 00:21:38 by iqabbal          ###   ########.fr       */
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
    first->h_x = data->player->x + (( -data->player->y + first->h_y )/tan(ray_angle));
    // printf("firsst xxxx:%f\n",first->h_x); 
      ///90= inf //270 inf     
}


 
double horizontal_intersection(t_data *data, double ray_angle)
{
    int		check;
    t_first first;
    double stepx;
    double stepy;

	check = 0;
	ray_angle = normalize_angle(ray_angle);
	first.y = floor(data->player->y / 40) * 40;
	if ((ray_angle > 0 && ray_angle < M_PI))
		first.y += 40;
	first.x = data->player->x + (first.y - data->player->y) / tan(ray_angle);
	stepy = 40;
	if (!(ray_angle > 0 && ray_angle < M_PI))
	{
		stepy *= -1;
		check = -1;
	}
	stepx = stepy / tan(ray_angle);
	if ((ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI) && stepx < 0)
		stepx *= -1;
	if (!(ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI) && stepx > 0)
		stepx *= -1;
    while (checkiswall(data, first.x, first.y, check, 1))
	{
		first.x += stepx;
		first.y += stepy;
	}
	//loop_check_wall_h(data, check);
	data->h_ray_dis_x = first.x;
	data->h_ray_dis_y = first.y;
	return (return_distance(data->player->x,first.x,data->player->y, first.y));
//     int check = 0;
//     t_first first;
//     ray_angle = normalize_angle(ray_angle);
//     first_intersection_horizontal(data,&first,ray_angle);
//     int ystep = 40;
//     if (!(ray_angle > 0 && ray_angle < M_PI))
// 	{
// 		ystep *= -1;
// 		check = -1;
// 	}
//     ray_angle = correction_angele(ray_angle);
//     double xstep = ystep/tan(ray_angle);
//     if ((ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI) && xstep < 0)
// 		xstep *= -1;
// 	if (!(ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI) && xstep > 0)
// 		xstep *= -1;
//     //ray_angle = correction_angele(ray_angle);
//      double h_x = first.h_x;
//      double h_y = first.h_y;
//     // if(check_wall(data,h_x,h_y))
//     //     return(return_distance(data->player->x,first.h_x,data->player->y,first.h_y));
//     int i = 10;
//    while(checkiswall(data, h_x, h_y, check, 1))
//    {
    
//         h_x += xstep;
//         h_y += ystep;
//         //check_wall(data,h_x,h_y);
//         //     break;
//         i--;
//         // printf(" x horizental after increment : %f\n",(h_x/data->size));
//         // printf(" y horizental after increment: %f\n",(h_y/data->size));
//    }
//     first.h_x = h_x;
//     first.h_y = h_y;
//     // printf("The distance horiz is :  %f\n",return_distance(data->player->x,first.h_x,data->player->y,first.h_y));
//      return(return_distance(data->player->x,first.h_x,data->player->y,first.h_y));
}


