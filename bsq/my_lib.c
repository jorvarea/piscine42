/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:35:44 by svaccaro          #+#    #+#             */
/*   Updated: 2023/07/26 22:11:39 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"

int	save_map_metadata(t_map *map, int file)
{
	char	ch;
	int		count;

	count = 0;
	if (get_number_rows_and_empty_char(file, map, &count) == 0)
		return (0);
	if (read(file, &ch, 1) > 0 && (ch >= 32 && ch <= 126) && count++)
		map->obstacle = ch;
	if (read(file, &ch, 1) > 0 && (ch >= 32 && ch <= 126) && count++)
		map->fill = ch;
	if (read(file, &ch, 1) > 0 && ch == '\n')
		;
	if (count == 4 && (map->empty != map->obstacle)
		&& (map->obstacle != map->fill) && (map->empty != map->fill))
		return (count);
	return (map_error());
}

int	check_if_newline(char ch, t_map *map, int *count_row, int *count_col)
{
	if (ch != '\n')
	{
		if (!check_char(map, ch))
			return (0);
		*count_col = *count_col + 1;
	}
	else if (count_col != 0 && map->total_columns == 0)
	{
		map->total_columns = *count_col;
		*count_col = 0;
		*count_row = *count_row + 1;
	}
	else if (map->total_columns != *count_col)
		return (map_error());
	else if (*count_col == 0)
		return (map_error());
	else
	{
		*count_col = 0;
		*count_row = *count_row + 1;
	}
	return (1);
}

int	get_size_map(t_map *map, int file)
{
	char	ch;
	int		count_row;
	int		count_col;

	map->total_columns = 0;
	count_row = 0;
	count_col = 0;
	if (save_map_metadata(map, file) == 4)
	{
		while (read(file, &ch, 1) > 0)
			check_if_newline(ch, map, &count_row, &count_col);
		if (count_row == 0 || count_row != map->total_rows)
			return (map_error());
	}
	else
		return (map_error());
	return (1);
}

int	check_map(t_map *map, char *filename)
{
	int	file;

	file = open(filename, O_RDONLY);
	if (file < 0)
		return (map_error());
	else
	{
		if (!get_size_map(map, file))
			return (0);
		close(file);
	}
	return (1);
}

int	get_map(char *filename, t_map *map)
{
	int		file;
	char	ch;
	int		cell;

	cell = 0;
	file = open(filename, O_RDONLY);
	if (file < 0)
		return (map_error());
	while (read(file, &ch, 1) > 0 && ch != '\n')
		;
	while (read(file, map->map[cell], map->total_columns) > 0
		&& cell < map->total_rows)
	{
		if (read(file, &ch, 1) > 0 && ch == '\n')
			++cell;
		else
			return (map_error());
	}
	close(file);
	return (1);
}
