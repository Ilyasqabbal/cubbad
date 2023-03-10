/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqabbal <iqabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:41:30 by anaji-el          #+#    #+#             */
/*   Updated: 2023/03/10 01:10:04 by iqabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Cub3d.h"

char *get_path(char *line)
{
	int count;
	char **split;

	line = ft_strtrim(line, "\n");
	// printf ("line--> %s\n", line);
	count = 0;
	split = ft_split(line, ' ');
	while (split[count])
		count++;
	if (count != 2)
		_error("Error\nInvalid teexture line");
	// Need to trim the line with \n to avoid the error
	// printf(">>>> %s\n", split[1]);
	return (&(*split[1]));
}

void is_valid_color(char *line, t_data *data, char color)
{
	t_var var;
	var.k = 1;
	var.i = 1;
	var.j = 0;
	var.p = 0;
	var.trim = ft_strtrim(line, " \n");
	while (var.trim[var.k])
	{
		var.k = var.i;
		if (ft_isdigit(var.trim[var.k]))
		{
			var.i = var.k;
			var.j = var.i;
			while (var.trim[var.i])
			{
				if (var.trim[var.i] == ',')
					break;
				var.i++;
			}
			var.rgb = ft_substr(var.trim, var.j, var.i - var.j);
			if (var.p < 3)
			{
				if (color == 'F')
					data->floor[var.p] = ft_atoi(var.rgb);
				else
					data->ciel[var.p] = ft_atoi(var.rgb);
				// data->floor[p] = atoi(rgb);
				// printf("---->%d", data->ciel[p]);
			}
			var.p++;
		}
		var.i++;
		var.k++;
	}
}

void check_identifiers(t_data *data, char *line, char **identifier)
{
	(void)data;
	if (*identifier == NULL)
		*identifier = get_path(line);
	else
		_error("Error\nDuplicate texture. Only one is allowed.\n");
}

int ftt_check(char *str, t_data *data)
{
	if (str[0] == '\n')
		return (0);
	if (ft_strncmp(str, "NO ", 3) == 0)
		check_identifiers(data, str, &data->no);
	else if (ft_strncmp(str, "SO ", 3) == 0)
		check_identifiers(data, str, &data->so);
	else if (ft_strncmp(str, "WE ", 3) == 0)
		check_identifiers(data, str, &data->we);
	else if (ft_strncmp(str, "EA ", 3) == 0)
		check_identifiers(data, str, &data->ea);
	else if (ft_strncmp(str, "F ", 2) == 0)
	{
		check_x(str, data);
		is_valid_color(str, data, 'F');
	}
	else if (ft_strncmp(str, "C ", 2) == 0)
	{
		check_x(str, data);
		is_valid_color(str, data, 'C');
	}
	else if (str[0] == '0' || str[0] == '1')
		return (1);
	else
		_error("Error\nNo identifier found\n");
	return (0);
}

int count_comma(char *str)
{
	int count;
	int i;
	int len;

	count = 0;
	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] == ',' && str[i + 1] == ',')
			_error("error\nBad textures");
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != ',' && str[i] != '\n')
			_error("Error\nNot digit");
		if (str[i] == ',')
			count++;
		if (ft_atoi(str + i) > 255 || ft_atoi(str + i) < 0)
			_error("Error\nNo color in this range");
		i++;
	}
	return (count);
}

void check_x(char *str, t_data *data)
{
	(void)data;
	if (ft_strncmp(str, "F ", 2) == 0)
	{
		if (count_comma(++str) != 2)
			_error("Error\n wrong texture");
	}
	else if (ft_strncmp(str, "C ", 2) == 0)
	{
		if (count_comma(++str) != 2)
			_error("Error\n wrong texture");
	}
}
