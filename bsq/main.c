/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:27:32 by svaccaro          #+#    #+#             */
/*   Updated: 2023/07/27 14:40:36 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib3.h"

int	check_and_solve_map(char *filename)
{
	int		i;
	t_map	map;

	if (check_map(&map, filename))
	{
		map.map = malloc(map.total_rows * sizeof(char *));
		if (map.map == NULL)
			return (map_error());
		i = 0;
		while (i < map.total_rows)
		{
			map.map[i] = malloc(map.total_columns * sizeof(char));
			if (map.map[i++] == NULL)
				return (map_error());
		}
		if (get_map(filename, &map))
		{
			find_biggest_square(&map);
			print_map(map);
		}
		while (i > 0)
			free(map.map[--i]);
		free(map.map);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	char	*filename;
	int		i;
	t_map	map;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			filename = argv[i];
			if (check_map(&map, filename))
				check_and_solve_map(filename);
			ft_putchar('\n');
			i++;
		}
	}
	return (0);
}
