/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_vertical.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqabbal <iqabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 00:45:35 by iqabbal           #+#    #+#             */
/*   Updated: 2023/03/11 02:33:23 by iqabbal          ###   ########.fr       */
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

int	checkiswall(t_data *data, double v_x, double v_y, int check, int face)
{
    // printf("hgg\n");
    double x,y;
	if (face == 1)
		v_y += check;
	else
		v_x += check;
	if (v_y > data->number_of_lines * 40)
		return (0);
	if (v_x > data->maximum_line * 40)
		return (0);
	x = floor(v_x / 40);
	y = floor(v_y / 40);
	if (y < 0 || y >= data->number_of_lines)
		return (0);
	if (x < 0 || x >= data->maximum_line)
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
	first.x = floor(data->player->x / data->size) * data->size;
	if ((ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI))
		first.x += data->size;
	if(to_degree(ray_angle) !=90  && to_degree(ray_angle) !=270)
		first.y = data->player->y + (first.x - data->player->x) * tan(ray_angle);
	else
		return(1000000);
	stepx = data->size;
	if (!(ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI))
	{
		stepx *= -1;
		check = -1;
	}
	if(to_degree(ray_angle) !=90  && to_degree(ray_angle) !=270)
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
	return (return_distance(data->player->x, data->v_ray_dis_x,data->player->y, data->v_ray_dis_y));
}