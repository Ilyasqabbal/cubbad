/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqabbal <iqabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 23:51:19 by anaji-el          #+#    #+#             */
/*   Updated: 2023/03/11 08:35:10 by iqabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Cub3d.h"

char	**read_file(char **av)
{
	char	**line;
	int		i;
	int		s;
	int		fd;

	i = 0;
	s = 0;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd))
		s++;
	if (s == 0)
		_error("Error\nEmpty file");
	close(fd);
	line = malloc(sizeof(char *) * (s + 1));
	if (!line)
		return (NULL);
	fd = open(av[1], O_RDONLY);
	while (i < s)
		line[i++] = get_next_line(fd);
	line[i] = NULL;
	close(fd);
	return (line);
}

void	create_map(t_data *data, char **file, int i)
{
	int		x;

	x = 0;
	while (file[i])
		data->map[x++] = file[i++];
}

void	allocate_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->map = malloc(sizeof(char *) * (data->number_of_lines + 1));
	if (!data->map)
		return ;
	while (i < data->number_of_lines)
	{
		j = 0;
		data->map[i] = malloc(sizeof(int) * (data->maximum_line + 1));
		if (!data->map)
			return ;
		while (j < data->maximum_line)
		{
			data->map[i][j] = ' ';
			j++;
		}
		i++;
	}
}

void	map_handling(t_data *data, char **file, int i)
{
	int		count;
	char	*trim;
	(void)trim;

	count = 0;
	data->maximum_line = longest_line(file);
	if (data->maximum_line == 0)
		_error("Error\nThere is no map");
	while (file[i])
	{
		trim = ft_strtrim(file[i], "\n");
		check_map(file[i]);
		count++;
		i++;
	}
	data->number_of_lines = count;
	if (data->number_of_lines == 0)
		_error("Error\nThere is no map");
}

void	missing_textures(t_data *data)
{
	if (data->no == NULL || data->we == NULL
		|| data->ea == NULL || data->so == NULL)
		_error("Error\nMissing texture");
	if (data->floor[0] == -1 || data->floor[1] == -1 || data->floor[2] == -1
		|| data->ciel[0] == -1 || data->ciel[1] == -1 || data->ciel[2] == -1)
		_error("Error\nInvalid texture line");
}

void parsing(t_data *data, char **file)
{
	int		i;
	char	*trim;

	i = 0;
	while (file[i])
	{

		trim = ft_strtrim(file[i], " ");
		if (ftt_check(trim, data))
			break ;
		i++;
		if (!trim)
			_error("Error\nThere is no path");
	}
	missing_textures(data);
	map_handling(data, file, i);
	allocate_map(data);
	create_map(data, file, i);
	check_first_last_line(data);
	check_up_down(data);
	count_player(data);
	player_position(data);
}

void print_map(t_data *data,char **map)
{
	int i = 0;
	int j;
	while(i < data->number_of_lines)
	{
		j = 0;
		while(j < data->maximum_line)
		{
			printf("%c",map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int  get_angle_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N')
				return(1);
			else if (data->map[i][j] == 'E')
				return(2);
			else if(data->map[i][j] == 'W')
				return(3);
			else if(data->map[i][j] == 'S')
				return(4);
			j++;
		}
		i++;
	}
	return(0);
}

void init_angle(t_data *data)
{
	data->player = malloc(sizeof(t_player));
	if(get_angle_player(data) == 1)
		data->player->angle = to_radian(270);
	else if(get_angle_player(data) == 2)
		data->player->angle = to_radian(0);
	else if(get_angle_player(data) == 3)
		data->player->angle = to_radian(180);
	else if(get_angle_player(data) == 4)
		data->player->angle = to_radian(90);
	
}
void init_player(t_data *data)
{
	init_angle(data);
	data->player->speed = 10;
    data->player->rotate_speed = to_radian(5);
	data->size = 40;
	player_position_(data);
	data->checker = false;
}

int main(int ac, char **av)
{
	t_data	data;
	int h, w;
	char	**file;
	(void)av;

	if (ac == 2 && check_arg(av[1]))
	{
		data.height_window = 500;
		data.width_window = 500;
		init_s(&data);
		file = read_file(av);
		parsing(&data, file);
		print_map(&data,data.map);
		data.mlx = mlx_init();
		data.mlx_win = mlx_new_window(data.mlx, data.height_window , data.width_window, "Cub3d");
		data.img.img_window  =  mlx_xpm_file_to_image(data.mlx, "/Users/iqabbal/Desktop/cuba-main/cud3d/img/xpm/red.xpm", &w, &h);
		if(w != 40 || h != 40)
			exit(1);
		data.img1.add_img = (unsigned int *)mlx_get_data_addr(data.img.img_window , \
		&data.img1.bit_pixel, &data.img1.line_len, &data.img1.endian);

		init_player(&data);
		//put_img_to_window(&data);
		mlx_loop_hook(data.mlx, &put_img_to_window, &data);
		mlx_hook(data.mlx_win,2,0,&all_moves,&data);
		mlx_loop(data.mlx);
	}
	else
		_error("Error\nBad arguments!");
}
