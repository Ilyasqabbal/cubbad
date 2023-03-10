/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqabbal <iqabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 07:45:12 by iqabbal           #+#    #+#             */
/*   Updated: 2023/03/10 10:07:02 by iqabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Cub3d.h"

void point(t_data *data)
{
    int i = 0;
    int x = (data->player->x / data->size) * 10;
    int y = (data->player->y / data->size) * 10;
    while(i < 6)
    {
        mlx_pixel_put(data->mlx,data->mlx_win,x + i,y,0x00000000);
        mlx_pixel_put(data->mlx,data->mlx_win,x,y - i,0x00000000);
        i++;
    }
    
}

int mini_map(t_data *data)
{
     int i = 0;
     int j = 0;
    int v = 5;
    int x;
    int y;
    data->img_wall= mlx_xpm_file_to_image(data->mlx,"img/xpm/red.xpm",&x,&y);
    data->img_floor = mlx_xpm_file_to_image(data->mlx,"img/xpm/yellow.xpm",&x,&y);
    data->player->img_player = mlx_xpm_file_to_image(data->mlx,"img/xpm/player.xpm",&x,&y);
    while(i < data->number_of_lines )
    {
        j = 0;
        while(j < data->maximum_line)
        {
            if(data->map[i][j] == '1')
                mlx_put_image_to_window(data->mlx,data->mlx_win,data->img_wall,j * v ,i*v);
            else if(data->map[i][j] == '0')
                mlx_put_image_to_window(data->mlx,data->mlx_win,data->img_floor,j * v,i*v);
            else if((data->map[i][j] == 'E' || data->map[i][j] == 'S' || data->map[i][j] == 'N' || data->map[i][j] == 'W' ) && data->checker == false)
            {
                point(data);
                 mlx_put_image_to_window(data->mlx,data->mlx_win,data->img_floor,j * v,i*v);
                 data->checker = true;
            }
            else if ((data->map[i][j] == 'E' || data->map[i][j] == 'S' || data->map[i][j] == 'N' || data->map[i][j] == 'W' )&& data->checker == true)
            {
                data->map[i][j] = '0';
            }
            else if(data->checker == true)
                 point(data);
            j++;
        }
        i++;
    }
    return(0);
}