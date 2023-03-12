/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqabbal <iqabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:53:35 by anaji-el          #+#    #+#             */
/*   Updated: 2023/03/12 05:29:26 by iqabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Cub3d.h"

void	check_map(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr(" 01NSEW\n", line[i]))
			_error("Error\nWrong map");
		i++;
	}
}

int	count_lines(char **line)
{
	int	count;

	count = 0;
	while (*line != NULL)
	{
		(*line)++;
		count++;
		line++;
	}
	return (count);
}

int	longest_line(char **line)
{
	int	i;
	int	j;
	int	longest_line;

	longest_line = 0;
	j = 0;
	while (line[j])
	{
		i = 0;
		line[j] = ft_strtrim(line[j], "\n");
		while (line[j][i])
			i++;
		if (longest_line < i)
			longest_line = i;
		j++;
	}
	return (longest_line);
}

// int	ft_check_up_down_map(char **map)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = count_lines(map) - 1;
// 	while (map[0][i] == '1' || map[0][i] == ' ')
// 		i++;
// 	if (i == ft_strlen(map[0]))
// 	{
// 		i = 0;
// 		while (map[j][i] == '1' || map[j][i] == ' ')
// 			i++;
// 		if (i == ft_strlen(map[j]))
// 			return (1);
// 	}
// 	_error("eeeerrrrrroooooorrrrrr\n");
// 	return (0);
// }

void	player_position(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'E'
				|| data->map[i][j] == 'W' || data->map[i][j] == 'S')
			{
				data->position.x = i;
				data->position.y = j;
				data->position.direction = data->map[i][j];
			}
			j++;
		}
		i++;
	}
}


void	player_position_(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'E'
				|| data->map[i][j] == 'W' || data->map[i][j] == 'S')
			{
				data->player->x = j * data->size + (data->size/2);
				data->player->y = i * data->size + (data->size/2);
				data->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}


