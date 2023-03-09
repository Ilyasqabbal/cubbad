/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqabbal <iqabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 00:45:59 by iqabbal           #+#    #+#             */
/*   Updated: 2023/03/09 06:14:17 by iqabbal          ###   ########.fr       */
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

#define SQ 40
int	check_wall(t_data *data,t_first *first, int check, int face)
{
	

	if (face == 1)
		first->v_y += check;
	else
        first->v_x += check;
	if (first->v_y > data->height * SQ)
		return (0);
	if (first->v_x > data->width * SQ)
		return (0);
	int x = floor(first->v_x / SQ);
	int y = floor(first->v_y / SQ);
	if (y < 0 || y >= (int)data->height)
		return (0);
	if (x < 0 || x >= (int)data->width)
		return (0);
    printf("x wall is : %d\n",x);
    printf("y wall is : %d\n",y);
	if (data->map[y][x] == '1')
		return (0);
	return (1);
}

// int check_wall(t_data *data,double x,double y)
// {
//     printf("x wall b  is : %f\n",x);
//     printf("y wall b is : %f\n",y);

//     printf("x p b  is : %f\n",data->player->x);
//     printf("y p  b is : %f\n",data->player->y);
//     int x_check = floor(x/40);
//     int y_check = floor(y/40);
    
//     //y_check *= 2;
//     x_check--;
//     y_check--;
//     // if(y_check < 0)
//     //     y_check *=-1;
//     // if(x_check < 0 )
//     //     x_check *=-1;
//     printf("x wall is : %d\n",x_check);
//     printf("y wall is : %d\n",y_check);
//     data->size++;
//     data->size--;
//     // if(data->map[y_check][x_check] == '1')
//     //     return(1);
    
//     return(0);
// }

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

