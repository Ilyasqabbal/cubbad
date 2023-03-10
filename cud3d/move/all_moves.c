/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqabbal <iqabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:28:03 by iqabbal           #+#    #+#             */
/*   Updated: 2023/03/10 03:05:35 by iqabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/move.h"
#include "../header/Cub3d.h"

 //window width / wall_strip_width

void draw_square(t_data *data,int x,int y)
{
    int i = 0;
    int xd = x;
    int yd = y;
    int j = 0;
    while(i < 40 )
    {
        j = 0;
        xd = x;
        while(j < 40)
        {
            if(j % 40 == 0 || i % 40 == 0 )
            {
                
            }
            else if(j % 40 == 39  || i % 40 == 39)
            {
                mlx_pixel_put(data->mlx, data->mlx_win, xd, yd,0xFF00000);
            }
            j++;
            xd++;
        }
        i++;
        yd++;
    }
}



void drawRay(t_data *data, double X0, double Y0, double X1, double Y1, double angle, double scale,int color)
{
	X1 = X1 + cos(angle) * scale;
	Y1 = Y1 + sin(angle) * scale;
    // printf("The X1 is : %f\n",X1/40);
    // printf("The Y1 is : %f\n",Y1/40);
	double dx = X1 - X0;
	double dy = Y1 - Y0;
    
	double steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);
    //printf("steps is : %f\n",steps);
	double Xinc = dx / (double)steps;
	double Yinc = dy / (double)steps;
	for (int i = 0; i <= steps; i++)
	{
		mlx_pixel_put(data->mlx, data->mlx_win,X0,Y0,color);
		X0 += Xinc;
		Y0 += Yinc;
	}
    check_wall1(data,X0,Y0,angle);
}

void draw_point(t_data *data)
{
    int i = 0;
    int x = data->player->x * 40;
    int y = data->player->y * 40;
    printf("x -- is : %d\n",x);
    printf("y -- is : %d\n",y);
    while(i < 6)
    {
        mlx_pixel_put(data->mlx,data->mlx_win,x + i,y,0x00000000);
        mlx_pixel_put(data->mlx,data->mlx_win,x,y - i,0x00000000);
        mlx_pixel_put(data->mlx,data->mlx_win,x - i,y,0x00000000);
        mlx_pixel_put(data->mlx,data->mlx_win,x - i,y,0x00000000);
        mlx_pixel_put(data->mlx,data->mlx_win,x,y + i,0x00000000);
        i++;
    }
    
}



void put_pixel(t_data *data,void(*f)(t_data *))
{
    if(f != NULL)
        f(data);
    //mlx_clear_window(data->mlx,data->mlx_win);
    //cast_All_rays(data);
    put_img_to_window(data);
   //draw_line1(data);
   //draw_a_ray(data);
    
}

int all_moves(int key,void *param)
{
    t_data *data;
    data = (t_data *)param;


    if(key == MOVE_UP)
        put_pixel(data,move_up);
    if(key == MOVE_DOWN)
        put_pixel(data,move_down);
    if(key == MOVE_LEFT)
        put_pixel(data,move_left);
    if(key == MOVE_RIGHT)
        put_pixel(data,move_reight);
    if(key == ROW_RIGHT)
    {
        data->player->angle = to_degree(data->player->angle);
        data->player->angle += 10;
        data->player->angle = (int)round(data->player->angle) % 360;
        data->player->angle = to_radian(data->player->angle);

    }
    if(key == ROW_LEFT)
    {
        data->player->angle = to_degree(data->player->angle);
        data->player->angle -= 10;
        data->player->angle = (int)round(data->player->angle) % 360;
        data->player->angle = to_radian(data->player->angle);

    }
    return(0);
}