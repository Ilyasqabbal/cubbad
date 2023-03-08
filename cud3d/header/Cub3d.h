/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqabbal <iqabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:29:32 by iqabbal           #+#    #+#             */
/*   Updated: 2023/03/08 02:24:46 by iqabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "move.h"
#include "../rendering/rendering.h"

typedef struct player t_player;

typedef struct line{
    float start_pointx;
    float start_pointy;
    float end_pointx;
    float end_pointy;
}t_line;

typedef struct data{
    //player
    t_player *player;
    t_line *line;
    void *img_floor;
    void *img_wall;
    char **map;
    unsigned int size;
    unsigned int width;
    unsigned int height;
    void	*mlx;
	void	*mlx_win;

}t_data;

typedef struct first_intersection{
    //cordination
    double h_x;
    double h_y;
    double v_x;
    double v_y;
    
    //facing
    int facing_left;
    int facing_down;
    int facing_up;
    int facing_right;
}t_first;


typedef struct s_rays{
    double ray_angle;
    double ray_distance;
    double fov ;
    double number_rays;
    double columid;
}t_rays;

//raycast
double      to_radian(double d);
double      to_degree(double r);
void        cast_All_rays(t_data *data);
void        first_intersection_horizontal(t_data *data,t_first *first,double ray_angle);
double      horizontal_intersection(t_data *data, double ray_angle);
void        first_intersection_vertical(t_data *data,t_first *first,double ray_angle);
double      vertical_intersection(t_data *data, double ray_angle);
int check_wall(t_data *data,double x,double y,int check,int face);
double      return_distance(double x1,double x2,double y1,double y2);
bool        is_facing_up(double ray_angle);
bool        is_facing_left(double ray_angle);
double      normalize_angle(double angle);
void        put_pixel(t_data *data,void(*f)(t_data *));
double correction_angele(double ray_angle);

void dsquare(t_data *data,int x,int y,int color,int draw);
#endif