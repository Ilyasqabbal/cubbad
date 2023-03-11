/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_horizontal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqabbal <iqabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 00:45:31 by iqabbal           #+#    #+#             */
/*   Updated: 2023/03/11 04:53:55 by iqabbal          ###   ########.fr       */
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
    if(to_degree(ray_angle) != 0  && to_degree(ray_angle) !=180)
		first.x = data->player->x + (first.y - data->player->y) / tan(ray_angle);
	stepy = 40;
	if (!(ray_angle > 0 && ray_angle < M_PI))
	{
		stepy *= -1;
		check = -1;
	}
	if(to_degree(ray_angle) != 0  && to_degree(ray_angle) !=180)
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
	data->h_ray_dis_x = first.x;
	data->h_ray_dis_y = first.y;
	return (return_distance(data->player->x,data->h_ray_dis_x,data->player->y, data->h_ray_dis_y));
}


