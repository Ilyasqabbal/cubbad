/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_vertical.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqabbal <iqabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 00:45:35 by iqabbal           #+#    #+#             */
/*   Updated: 2023/03/10 00:30:14 by iqabbal          ###   ########.fr       */
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
    ray_angle = correction_anglev(ray_angle);
    first->v_y = data->player->y + ((-data->player->x + first->v_x )*tan(ray_angle));
    check_wall1(data,first->v_x,first->v_y,ray_angle);
}

int	checkiswall(t_data *data, double v_x, double v_y, int check, int face)
{
    double x,y;
	if (face == 1)
		v_y += check;
	else
		v_x += check;
	if (v_y > data->height * 40)
		return (0);
	if (v_x > data->width * 40)
		return (0);
	x = floor(v_x / 40);
	y = floor(v_y / 40);
	if (y < 0 || y >= data->height)
		return (0);
	if (x < 0 || x >= data->width)
		return (0);
	if (data->map[(int)y][(int)x] == '1')
		return (0);
	return (1);
}

double vertical_intersection(t_data *data, double ray_angle)
{
    int		check;
    t_first first;
    
    double stepx;
    double stepy;
	check = 0;
	ray_angle = normalize_angle(ray_angle);
	first.x = floor(data->player->x / 40) * 40;
	if ((ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI))
		first.x += 40;
	first.y = data->player->y + (first.x - data->player->x) * tan(ray_angle);
	stepx = 40;
	if (!(ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI))
	{
		stepx *= -1;
		check = -1;
	}
	stepy = stepx * tan(ray_angle);
	if (!(ray_angle > 0 && ray_angle < M_PI) && stepy > 0)
		stepy *= -1;
	if ((ray_angle > 0 && ray_angle < M_PI) && stepy < 0)
		stepy *= -1;
	while(checkiswall(data,first.x, first.y, check, 0))
    {
        first.x += stepx;
        first.y += stepy;
    } 
	data->v_ray_dis_x = first.x;
	data->v_ray_dis_y = first.y;
	return (return_distance(data->player->x, first.x,data->player->y, first.y));
    // t_first first;
    // int		check;

	// check = 0;
    // ray_angle = normalize_angle(ray_angle);
    // first_intersection_vertical(data,&first,ray_angle);
    // int xstep = 40;
    // if (!(ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI))
	// {
    //     xstep *= -1;
    //     check = -1;
	// }
    // ray_angle = correction_anglev(ray_angle);
    // double ystep = xstep * tan((ray_angle));
    // if (!(ray_angle > 0 && ray_angle < M_PI) && ystep > 0)
	// 	ystep *= 1;
	// if ((ray_angle > 0 && ray_angle < M_PI) && ystep < 0)
	// 	ystep *= 1;
    // double v_x = first.v_x;
    // double v_y = first.v_y;
    // // if(check_wall(data,v_x,v_y))
    // //         return(return_distance(data->player->x,first.v_x,data->player->y,first.v_y));
    // int i = 10;
    // while(checkiswall(data, v_x, v_y, check, 0))
    // {
    //     //check_wall(data,&first,check,0);
    //     //if(check_wall1(data,v_x,v_y,ray_angle))
    //     //    break;
    //     v_x += xstep;
    //     v_y += ystep;
    //     // if(check_wall(data,v_x,v_y))
    //     //     break;
    //     i--;
    //     // printf(" x vertical after increment : %f\n",fabs(v_x/data->size));
    //     // printf(" y vertical after increment: %f\n",fabs(v_y/data->size));
    // } 
    // first.v_x = v_x;
    // first.v_y = v_y;
    // // printf("angle is : %f\n",to_degree(ray_angle));
    // // printf("first x vertical : %f\n",fabs(v_x/data->size));
    // // printf("first y vertical : %f\n",fabs(v_y/data->size));
    // // printf("The distance vert is :  %f\n",return_distance(data->player->x,first.v_x,data->player->y,first.v_y));
    // return(return_distance(data->player->x,first.v_x,data->player->y,first.v_y));
}