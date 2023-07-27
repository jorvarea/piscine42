/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lib2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:37:09 by svaccaro          #+#    #+#             */
/*   Updated: 2023/07/27 14:40:12 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib2.h"
#include <stdio.h>

int	get_dist_row(t_map *map, int **dist_row)
{
	int	row;
	int	col;
	int	count_distance;

	row = 0;
	*dist_row = malloc(map->total_rows * sizeof(int));
	if (dist_row == NULL)
		return (0);
	while (row < map->total_rows)
	{
		col = 0;
		(*dist_row)[row] = 0;
		while (col < map->total_columns)
		{
			count_distance = 0;
			while (col < map->total_columns
				&& map->map[row][col] != map->obstacle)
			{
				count_distance++;
				col++;
			}
			if (count_distance > (*dist_row)[row])
				(*dist_row)[row] = count_distance;
			col++;
		}
		row++;
	}
	return (1);
}

int	get_dist_col(t_map *map, int **dist_col)
{
	int	row;
	int	col;
	int	count_distance;

	col = 0;
	*dist_col = malloc(map->total_columns * sizeof(int));
	if (dist_col == NULL)
		return (0);
	while (col < map->total_columns)
	{
		row = 0;
		(*dist_col)[col] = 0;
		while (row < map->total_rows)
		{
			count_distance = 0;
			while (row < map->total_rows && map->map[row][col] != map->obstacle)
			{
				count_distance++;
				row++;
			}
			if (count_distance > (*dist_col)[col])
				(*dist_col)[col] = count_distance;
			row++;
		}
		col++;
	}
	return (1);
}

int	get_common_max_posible(t_map *map, int *dist_row, int *dist_col)
{
	int	index_row;
	int	index_col;
	int	*dist_row_copy;
	int	*dist_col_copy;

	dist_row_copy = copy_array_int(dist_row, map->total_rows);
	dist_col_copy = copy_array_int(dist_col, map->total_columns);
	ft_sort_int_tab(dist_row_copy, map->total_rows);
	ft_sort_int_tab(dist_col, map->total_columns);
	index_row = map->total_rows - 1;
	while (index_row >= 0)
	{
		index_col = map->total_columns - 1;
		while (index_col >= 0)
		{
			if (dist_col[index_col] == dist_row[index_row])
			{
				free(dist_row_copy);
				free(dist_col_copy);
				return (dist_row[index_row]);
			}
			index_col--;
		}
		index_row--;
	}
	free(dist_row_copy);
	free(dist_col_copy);
	return (0);
}

int	is_size_possible_row(t_map *map, int size_to_try, int *dist_row)
{
	int	count_sucession;
	int	i;

	count_sucession = 0;
	i = 0;
	while (i < map->total_rows)
	{
		while (i < map->total_rows && i <= size_to_try
			&& dist_row[i] >= size_to_try)
		{
			count_sucession++;
			i++;
		}
		if (count_sucession == size_to_try)
			return (1);
		else
			count_sucession = 0;
		i++;
	}
	return (0);
}

int	is_size_possible_col(t_map *map, int size_to_try, int *dist_col)
{
	int	count_sucession;
	int	i;

	count_sucession = 0;
	i = 0;
	while (i < map->total_columns)
	{
		while (i < map->total_columns && i <= size_to_try
			&& dist_col[i] >= size_to_try)
		{
			count_sucession++;
			i++;
		}
		if (count_sucession == size_to_try)
			return (1);
		else
			count_sucession = 0;
		i++;
	}
	return (0);
}
