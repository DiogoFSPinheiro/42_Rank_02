/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:53:50 by diogosan          #+#    #+#             */
/*   Updated: 2024/06/26 11:29:45 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_get_dimensions(int *x, int *y, char *filename)
{
	char	*line;
	int		fd;

	*y = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_clean(fd, "Error -> Not a file or not enough Permissions\n");
	line = get_next_line(fd);
	if (!line)
		ft_error_clean(fd, "Error -> No info on file\n");
	*x = words(line, ' ');
	while (line)
	{
		*y = *y + 1;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

void	ft_set_point(t_point *point, char *str, int x, int y)
{
	char	**data;

	data = ft_split(str, ',');
	point->z = ft_atoi(data[0]);
	point->x = x;
	point->y = y;
	if (data[1])
		point->color = ft_rgb_to_int(data[1]);
	else
		point->color = 0xffffff;
	free_args(data);
}

void	ft_fill_matix(t_point *row, char *line, int y) // preenche a matriz
{
	char	**data;
	int		c;

	c = 0;
	data = ft_split(line, ' ');
	while (data[c])
	{
		ft_set_point(&row[c], data[c], c, y);
		free(data[c]);
		c++;
	}
	free(data);
}

t_map	*ft_convert_data(char *filemap)
{
	t_map	*map;
	char	*line;
	int		fd;
	int		x;
	int		y;

	ft_get_dimensions(&x, &y, filemap);
	map = malloc(sizeof(t_map));
	map->width = x;
	map->height = y;
	map->coord = malloc(map->height * sizeof(t_point *));
	y = 0;
	fd = open(filemap, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		map->coord[y] = malloc(map->width * sizeof(t_point));
		ft_fill_matix(map->coord[y], line, y);
		free(line);
		y++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (map);
}
