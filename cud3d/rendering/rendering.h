/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqabbal <iqabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:43:44 by iqabbal           #+#    #+#             */
/*   Updated: 2023/03/11 03:23:28 by iqabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
#define RENDERING_H

#include "../header/Cub3d.h"
#include "../header/move.h"

typedef struct data t_data;
typedef struct first_intersection t_first;
typedef struct s_rays t_rays;
typedef struct s_render
{
    int widht;
    int height;
    double distance_proj_plan;
    double wall_stripe_height;
    double ray_distance;
    double fov;
    int size;
   
}t_render;

void render(t_data *data,t_rays *r);
void render_floor();
void render_ciel();
void render_wall();

void point(t_data *data);
int mini_map(t_data *data);

t_render *init_struct_render(t_data *data,t_rays *ra);
double calcul_stripe_height(t_data *data,t_render *r,double distance_proj_plan,int di);
double calcul_proj_plan(t_data *data,t_render *r);

//img
void create_img(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
#endif