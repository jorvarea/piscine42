/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_basic_functions2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:39:31 by jorvarea          #+#    #+#             */
/*   Updated: 2023/07/27 10:52:08 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_basic_functions2.h"

int	check_char(t_map *map, char ch)
{
	if (map->empty != ch && map->obstacle != ch)
		return (map_error());
	return (1);
}

int	map_error(void)
{
	ft_putstr("map error");
	return (0);
}

int	get_number_rows_and_empty_char(int file, t_map *map, int *count)
{
	char	*integer;
	char	ch;

	integer = (char *)malloc(10 * sizeof(char));
	if (integer == NULL)
		return (map_error());
	while (read(file, &ch, 1) > 0 && (ch >= '0' && ch <= '9'))
	{
		integer[*count] = ch;
		*count = *count + 1;
	}
	map->total_rows = ft_atoi(integer);
	free(integer);
	*count = 0;
	if (map->total_rows)
		*count = *count + 1;
	if ((ch >= 32 && ch <= 126))
	{
		map->empty = ch;
		*count = *count + 1;
	}
	return (1);
}

void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	min_index;

	i = 0;
	j = 0;
	while (i < size)
	{
		min_index = i;
		j = i + 1;
		while (j < size)
		{
			if (tab[j] < tab[min_index])
				min_index = j;
			j++;
		}
		if (min_index != i)
			ft_swap(&tab[i], &tab[min_index]);
		i++;
	}
}
