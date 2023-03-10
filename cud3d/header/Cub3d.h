/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqabbal <iqabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:29:32 by iqabbal           #+#    #+#             */
/*   Updated: 2023/03/10 01:46:15 by iqabbal          ###   ########.fr       */
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
#include <fcntl.h>
#include "move.h"
#include "../rendering/rendering.h"
#include "../gnl/get_next_line.h"

typedef struct player t_player;

//parse
typedef struct s_position
{
	int		x;
	int		y;
	char	direction;
}	t_position;

typedef struct s_var
{
	char	*trim;
	char	*rgb;
	int		k;
	int		i;
	int		j;
	int		p;
}t_var;

typedef struct data{
    //player
    t_player    *player;
    void        *img_floor;
    void        *img_wall;
    char		**map;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			floor[3];
	int			ciel[3];
	char		**line;
	int			number_of_lines;
	int			maximum_line;
    unsigned int size;
    unsigned int width;
    unsigned int height;
    void	*mlx;
	void	*mlx_win;
    double h_ray_dis_x;
    double h_ray_dis_y;
    double v_ray_dis_x;
    double v_ray_dis_y;
    t_position	position;
}t_data;

typedef struct first_intersection{
    //cordination
    double h_x;
    double h_y;
    double v_x;
    double v_y;
    double x;
    double y;
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


//parse
char	*ft_strtrim(char const *s1, char const *set);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
char	**ft_split(char const *s, char c);
int		ftt_check(char *str, t_data *data);
char	*ft_substr(char const *s, int start, int len);
void	init_s(t_data *data);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	_error(char *str);
int		first_line(char	*map);
int		last_line(char **map);
void	check_map(char *map);
void	check_x(char *str, t_data *data);
int		count_lines(char **line);
int		longest_line(char **line);
int		check_arg(char *str);
int		ft_check_up_down_map(char **map);
void	check_up_down(t_data *data);
void	count_player(t_data *data);
void	check_first_last_line(t_data *data);
void	player_position(t_data *data);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
//raycast
double      to_radian(double d);
double      to_degree(double r);
void        cast_All_rays(t_data *data);
void        first_intersection_horizontal(t_data *data,t_first *first,double ray_angle);
double      horizontal_intersection(t_data *data, double ray_angle);
void        first_intersection_vertical(t_data *data,t_first *first,double ray_angle);
double      vertical_intersection(t_data *data, double ray_angle);
int         check_wall(t_data *data,t_first *first, int check, int face);
int check_wall1(t_data *data,double x,double y,int ray_angle);
double      return_distance(double x1,double x2,double y1,double y2);
bool        is_facing_up(double ray_angle);
bool        is_facing_left(double ray_angle);
double      normalize_angle(double angle);
void        put_pixel(t_data *data,void(*f)(t_data *));
double correction_angele(double ray_angle);

double correction_anglev(double ray_angle);
void dsquare(t_data *data,int x,int y,int color,int draw);
int	checkiswall(t_data *data, double v_x, double v_y, int check, int face);


void	player_position_(t_data *data);
#endif