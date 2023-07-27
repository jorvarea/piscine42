/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lib3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:29:50 by jorvarea          #+#    #+#             */
/*   Updated: 2023/07/27 14:41:11 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib3.h"

int	get_biggest_size(t_map *map)
{
	int	*dist_row;
	int	*dist_col;
	int	common_max_possible;

	dist_row = NULL;
	dist_col = NULL;
	common_max_possible = 0;
	if (get_dist_row(map, &dist_row) && get_dist_col(map, &dist_col))
		common_max_possible = get_common_max_posible(map, dist_row, dist_col);
	while (common_max_possible > 0)
	{
		if (is_size_possible_row(map, common_max_possible, dist_row)
			&& is_size_possible_col(map, common_max_possible, dist_col))
		{
			free(dist_row);
			free(dist_col);
			return (common_max_possible);
		}
		else
			common_max_possible--;
	}
	free(dist_row);
	free(dist_col);
	return (0);
}

void	find_biggest_square(t_map *map)
{
	int	biggest_square;

	ft_putstr("The biggest square possible will have a maximum size of ");
	biggest_square = get_biggest_size(map);
	ft_putnbr(biggest_square);
	ft_putchar('\n');
}
