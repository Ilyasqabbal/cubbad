/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqabbal <iqabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:53:54 by iqabbal           #+#    #+#             */
/*   Updated: 2023/03/08 01:31:48 by iqabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

    // int widht;
    // int height;
    // double distance_proj_plan;
    // double wall_stripe_height;
    // double ray_distance;
    // int size;

double calcul_proj_plan(t_data *data,t_render *r)
{
    double res;

    res = (data->width/2)/tan(r->fov);
    return(res);
}
double calcul_stripe_height(t_data *data,t_render *r,double distance_proj_plan)
{
    double res;
    res = (data->size/r->ray_distance) * distance_proj_plan;
    return(res);
}
t_render *init_struct_render(t_data *data,t_rays *ra)
{
    t_render *r = malloc(sizeof(t_render));
    
    r->widht = data->width;
    r->height = data->height;
    r->fov = ra->fov / 2;
    r->ray_distance = ra->ray_distance;
    r->size = data->size;
    r->distance_proj_plan = calcul_proj_plan(data,r);
    r->wall_stripe_height = calcul_stripe_height(data,r,r->distance_proj_plan);
    return(r);
    
}



void dsquare(t_data *data,int x,int y,int color,int draw)
{
    int i = 0;
    int xd = x;
    int yd = y;
    int j = 0;
    while(i < draw )
    {
        j = 0;
        xd = x;
        while(j < draw)
        {
            mlx_pixel_put(data->mlx, data->mlx_win, xd, yd,color);
            j++;
            xd++;
        }
        i++;
        yd++;
    }
}
void render_ciel(int top,t_data *data,double columid,int color){
    //top = top - 1;
    while(top >= 0)
    {
        dsquare(data,columid * 40 ,top * 40,color,40);
        //mlx_pixel_put(data->mlx, data->mlx_win,columid * 40,top * 40,0xFF00000);
        top--;
    }
     //put_img_to_window(data);
}

void render_floor(int bottom,t_data *data,double columid,int color)
{
    bottom--;
    while(bottom  < 600/40)
    {
        dsquare(data,columid * 40,bottom* 40,color,40);
       // mlx_pixel_put(data->mlx, data->mlx_win,columid * 40,bottom * 40,0xFF00000);
       bottom++;
    }
}

void render_wall(int top,int bottom,t_data *data,double columid)
{
    top++;
    while(top <= bottom)
    {
       // mlx_pixel_put(data->mlx, data->mlx_win,columid * 40 ,top * 40,0xFF00000);
        draw_square(data,columid * 40 ,top * 40);
        top++;
    }
}
void render(t_data *data,t_rays *r)
{
    
    printf("heeeelo\n");
    t_render *render;
    render = init_struct_render(data,r);
    double top;
    double bottom;

    top = (data->height / 2) - (render->wall_stripe_height / 2);
    bottom = (render->wall_stripe_height) + top + top;
   //render_ciel(top,data,r->columid,0xFFFFFF);
    render_wall(top,bottom,data,r->columid);
    render_floor(bottom,data,r->columid,0x00FFFFF);
}