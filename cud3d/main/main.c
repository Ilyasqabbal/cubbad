/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqabbal <iqabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:16:33 by iqabbal           #+#    #+#             */
/*   Updated: 2023/03/08 02:47:30 by iqabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Cub3d.h"


int put_img_to_window(t_data *data)
{
    unsigned int i = 0;
    unsigned int j = 0;
    int v = 40;
    int x;
    int y;
        data->img_wall= mlx_xpm_file_to_image(data->mlx,"img/xpm/red.xpm",&x,&y);
        data->img_floor = mlx_xpm_file_to_image(data->mlx,"img/xpm/yellow.xpm",&x,&y);
        data->player->img_player = mlx_xpm_file_to_image(data->mlx,"img/xpm/player.xpm",&x,&y);
    while(i < data->height )
    {
        j = 0;
        while(j < data->width)
        {
            if(data->map[i][j] == '1')
                mlx_put_image_to_window(data->mlx,data->mlx_win,data->img_wall,j * v ,i*v);
            else if(data->map[i][j] == '0')
                mlx_put_image_to_window(data->mlx,data->mlx_win,data->img_floor,j * v,i*v);
            else if(data->map[i][j] == 'E')
                 mlx_put_image_to_window(data->mlx,data->mlx_win,data->img_floor,j * v,i*v);
             draw_square(data,j*v,i*v);
            j++;
        }
        i++;
    }
     drawRay(data, data->player->x, data->player->y, data->player->x, data->player->y,data->player->angle, 40,0x00000000);
    cast_All_rays(data);
    draw_point(data);
    return(0);
}


int main()
{

    t_data data;

    //init pointer
    data.player    =  malloc(sizeof(t_player));
    data.map       =  malloc(11 *sizeof(char *));
    data.player->data = malloc(sizeof(t_data));
    data.player->data->map = malloc(11 *sizeof(char *));
    data.line = malloc(sizeof(t_line));
    
    //init player cordination;
    data.player->speed = 10;
    data.player->rotate_speed = 5 * (M_PI / 180);
    data.player->angle = 90 * (M_PI /180);
    data.player->x = 2 * 40 ;
    data.player->y = 2 * 40  ;
    data.size = 40;
    
    
    //line
    data.line->start_pointx = data.player->y;
    data.line->start_pointy = data.player->x;
    data.line->end_pointx = data.player->x;
    data.line->end_pointy = data.player->y + 40;


    //------------------------------- *     //8 * 40  =320 //200  ===>
    data.map[0]  =  "11111111111" ;//|
    data.map[1]  =  "10000000001" ;//|
    data.map[2]  =  "10000000001" ;//|
    data.map[3]  =  "10000111101" ;//|
    data.map[4]  =  "10000E00101" ;//|
    data.map[5]  =  "10000000101" ;//|
    data.map[6]  =  "10000000101" ;//|
    data.map[7]  =  "10000111101" ;//|
    data.map[8]  =  "10000000001" ;//|
    data.map[9]  =  "10000000001" ;//|
    data.map[10] =  "11111111111" ;//|
    //------------------------------- *
    
    
    data.height = 11;
    data.width = 11;
    
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 800 , 600, "Hello world!");
    put_img_to_window(&data);
    //draw_line1(&data);
    mlx_loop_hook(data.mlx, &put_img_to_window, &data);
    mlx_hook(data.mlx_win,2,0,&all_moves,&data);
	mlx_loop(data.mlx);
    
}





