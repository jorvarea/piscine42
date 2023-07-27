/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_basic_functions3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:22:41 by jorvarea          #+#    #+#             */
/*   Updated: 2023/07/27 14:33:47 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_basic_functions3.h"

int	*copy_array_int(int *array, int size)
{
	int	i;
	int	*copy;

	copy = malloc(size * sizeof(int));
	i = 0;
	while (i < size)
	{
		copy[i] = array[i];
		i++;
	}
	return (copy);
}

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
