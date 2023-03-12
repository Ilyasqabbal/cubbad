/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqabbal <iqabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:43:37 by iqabbal           #+#    #+#             */
/*   Updated: 2023/03/12 04:51:43 by iqabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

double calcul_proj_plan(t_data *data,t_render *r)
{
    double res;

    res = (data->width_window/2)/tan(r->fov);
    return(res  );
}
double calcul_stripe_height(t_data *data,t_render *r,double distance_proj_plan,int di)
{
    (void)di;
    double res;
    res = (data->size / r->ray_distance) * distance_proj_plan;
    return(res);
}

t_render *init_struct_render(t_data *data,t_rays *ra)
{
    t_render *r = malloc(sizeof(t_render));
    r->widht = data->width_window;
    r->height = data->height_window;
    r->fov = ra->fov / 2;
    // if(data->cor == 1)
        r->ray_distance =  ra->ray_distance * cos(ra->ray_angle - data->player->angle);  //cos(correction_anglev(ra->ray_angle));
    // else
    //     r->ray_distance =  ra->ray_distance * cos(ra->ray_angle - data->player->angle);  //cos(correction_angele(ra->ray_angle));
    
    r->size = data->size;
    r->distance_proj_plan = calcul_proj_plan(data,r);
    r->wall_stripe_height = calcul_stripe_height(data,r,r->distance_proj_plan,ra->columid);
    return(r);
    
}
//i hiya colium id