/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqabbal <iqabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 00:45:59 by iqabbal           #+#    #+#             */
/*   Updated: 2023/03/08 07:17:50 by iqabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Cub3d.h"

double	normalize_angle(double angle)
{
	while (angle < 0)
	{
        angle+= 2  * M_PI;
		
	}
	return (angle);
}

int check_wall(t_data *data,double x,double y,int check,int face)
{
    return(0);
}

double return_distance(double x1,double x2,double y1,double y2)
{ 
    int dx = x2 - x1;
    dx = pow(dx,2);
    int dy = y2 - y1;
    dy = pow(dy,2);
    return(sqrt(dx + dy));
}

bool is_facing_up(double ray_angle)
{
    if(ray_angle < 360 && ray_angle >  180)
        return(true);
    return(false);
}

bool is_facing_left(double ray_angle)
{
    if(ray_angle > 90 && ray_angle <  270)
        return(true);
    return(false); 
}

