/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqabbal <iqabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 00:45:59 by iqabbal           #+#    #+#             */
/*   Updated: 2023/03/10 00:23:48 by iqabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Cub3d.h"

double	normalize_angle(double angle)
{
	angle = fmod(angle, (2 * M_PI));
	if (angle < 0)
		angle = angle + (2 * M_PI);
	return (angle);
	return (angle);
}

#define SQ 40
// int	check_wall(t_data *data,t_first *first, int check, int face)
// {
	

// 	if (face == 1)
// 		first->v_y += check;
// 	else
//         first->v_x += check;
// 	if (first->v_y > data->height * SQ)
// 		return (0);
// 	if (first->v_x > data->width * SQ)
// 		return (0);
// 	int x = floor(first->v_x / SQ);
// 	int y = floor(first->v_y / SQ);
// 	if (y < 0 || y >= (int)data->height)
// 		return (0);
// 	if (x < 0 || x >= (int)data->width)
// 		return (0);
//     printf("x wall is : %d\n",x);
//     printf("y wall is : %d\n",y);
// 	if (data->map[y][x] == '1')
// 		return (0);
// 	return (1);
// }
typedef struct s_firo{
    double x;
    double y;
}t_firo;
t_firo  *dda_(double X0,double Y0,double X1,double Y1,double ray_angle,double scale)
{
    t_firo *k = malloc(sizeof(t_firo));
    X1 = X1 + cos(ray_angle) * scale;
	Y1 = Y1 + sin(ray_angle) * scale;
	double dx = X1 - X0;
	double dy = Y1 - Y0;
	double steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);
	double Xinc = dx / (double)steps;
	double Yinc = dy / (double)steps;
    k->x = Xinc * steps;
	k->y = Yinc * steps;
    return k;
}


double return_distance(double x1,double x2,double y1,double y2)
{ 
    int dx = x2 - x1;
    dx = pow(dx,2);
    int dy = y2 - y1;
    dy = pow(dy,2);
    return(sqrt(dx + dy));
}

int check_wall1(t_data *data,double x,double y,int ray_angle)
{
    ray_angle++;
    data->size++;
    data->size--;
    //t_firo *g = malloc(sizeof(t_firo));
    //g = dda_(data->player->x,data->player->y,data->player->x,data->player->y,ray_angle,return_distance(data->player->x,x,data->player->y,y));
    int check_x = floor(x/40);
    int check_y = floor(y/40);
    check_x--;
    int h = data->height;
    //int w = data->width;
    if(check_y < 0)
        check_y *=-1;
    if(check_y == -2147483648)
        check_y = 10;
    printf("x is : %d\n",check_x);
    printf("y is : %d\n",check_y);
    if(check_y < h)
    {
    //if(data->map[check_y][check_x] == '1')
    // {
    //     printf("hello wall");
    //    return(1);
    // }
    }
    return(0);
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

