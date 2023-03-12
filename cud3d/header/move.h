/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqabbal <iqabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:18:16 by iqabbal           #+#    #+#             */
/*   Updated: 2023/03/12 05:05:30 by iqabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
#define MOVE_H

#include "Cub3d.h"

#define MOVE_UP 13
#define MOVE_DOWN 1
#define MOVE_LEFT 0
#define MOVE_RIGHT 2
#define ROW_RIGHT 124
#define ROW_LEFT 123

//struct player info
typedef struct data t_data;

typedef struct player{
    float x;
    float y;
    double angle;
    double speed;
    double rotate_speed;
    void *img_player;
    t_data *data;
}t_player;

// --
//moves
void move_up(t_data *data);
void move_down(t_data *data);
void move_reight(t_data *data);
void move_left(t_data *data);
int all_moves(int key,void *param);
int check_next_position(t_data *data,int flag);


//player position
int all_position(char **map, int x, int y);
int x_player(char **map);
int y_player(char **map);


void draw_line1(t_data *data);
int put_img_to_window(t_data *data);
void draw_point(t_data *data);
void drawRay(t_data *data, double X0, double Y0, double X1, double Y1, double angle,double scale,int color);
void draw_line(void *mlx_ptr, void *win_ptr, int x1, int y1, int x2, int y2);
void cast_All_rays(t_data *data);

//con
double ft_radian_to_degree(double angleR);
double ft_degree_to_radian(double angleD);
void draw_square(t_data *data,int x,int y);
#endif



/*
*/