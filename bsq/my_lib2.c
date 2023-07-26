/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lib2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:37:09 by svaccaro          #+#    #+#             */
/*   Updated: 2023/07/26 23:25:22 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib2.h"

void	print_map(t_map map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map.total_rows)
	{
		col = 0;
		while (col < map.total_columns)
		{
			ft_putchar(map.map[row][col]);
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}

t_pos	*get_obstacle_pos(t_map *map)
{
	t_pos	*obstacle_map;
	int		iterator;
	int		row;
	int		col;

	iterator = 0;
	row = 0;
	col = 0;
	while (map.map[row][col] && row < map.total_rows)
	{
		col = 0;
		while (col < map.total_columns)
		{
			if (map.map[row][col] == map.obstacle)
			{
				obstacle_map[iterator].row_pos = row;
				obstacle_map[iterator].col_pos = col;
				iterator++;
			}
			col++;
		}
		row++;
	}
	return (obstacle_map);
}

int	*get_dist_row(t_pos *obstacle_map, int max)
{
	int	*dist_row;
	int	obs;
	int	iterator;
	int	i;

	i = 0;
	while (i < max)
	{
		if (obstacle_map[iterator]->row_pos == i)
		{
			obs = obstacle_map->col_pos;
		}
		else
			obs = max;
	}
	return ();
}

int	get_biggest_size(t_map *map, t_pos *obstacle_map)
{
	int	max_size;
	int	*max_dist_row;
	int	*max_dist_col;

	if (map->total_rows > map->total_columns)
		max_size = map->total_columns;
	else
		max_size = map->total_rows;
	max_dist_row = get_dist_row(obstacle_map, max_size);
	max_dist_col = get_dist_col(obstacle_map, max_size);
	max_size = get_common_max_posible(max_dist_row, max_dist_col);
}

void	find_biggest_square(t_map *map)
{
	t_pos *obstacle_map;
	int biggest_square;

	obstacle_map = get_obstacle_pos(map);
	biggest_square = get_biggest_size(map, obstacle_map);
}