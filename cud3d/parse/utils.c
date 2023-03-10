/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqabbal <iqabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:12:58 by anaji-el          #+#    #+#             */
/*   Updated: 2023/03/10 01:08:58 by iqabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Cub3d.h"

int	check_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] == 'b' && str[i - 2] == 'u'
		&& str[i - 3] == 'c' && str[i - 4] == '.')
		return (1);
	else
		_error("Error\nMap extension is not valid\n");
	exit (0);
}


void	check_up_down(t_data *data)
{
	int	j;
	int	i;

	j = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{	
			if (data->map[j][i] == '0')
				if ((!data->map[j - 1][i] || data->map[j - 1][i] == ' ')
					|| (!data->map[j + 1][i] || data->map[j + 1][i] == ' ')
					|| (!data->map[j][i + 1] || data->map[j][i + 1] == ' ')
					|| (!data->map[j][i - 1] || data->map[j][i - 1] == ' '))
					_error("Error\nWrong map");
			i++;
			// printf("%d\n", data->map[j][i]);
		}
		j++;
	}
}

void	count_player(t_data *data)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S' ||
				data->map[i][j] == 'W' || data->map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		_error("Error\nMap should have one player\n");
}

void check_first_last_line(t_data *data)
{
    if (ft_strchr(data->map[0], '0')
		|| ft_strchr(data->map[data->number_of_lines - 1], '0') ||
        ft_strchr(data->map[0], 'N')
			|| ft_strchr(data->map[data->number_of_lines - 1], 'N') ||
        ft_strchr(data->map[0], 'S')
			|| ft_strchr(data->map[data->number_of_lines - 1], 'S') ||
        ft_strchr(data->map[0], 'E')
			|| ft_strchr(data->map[data->number_of_lines - 1], 'E') ||
        ft_strchr(data->map[0], 'W')
			|| ft_strchr(data->map[data->number_of_lines - 1], 'W'))
    {
        _error("Error\nWrong Map\n");
    }
}
