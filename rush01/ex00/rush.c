/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:31:54 by jorvarea          #+#    #+#             */
/*   Updated: 2023/07/16 22:17:33 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_grid(int array[4][4]);
int		take_parameters(char *str, int *parameter_array);
int		check_parameters(int *parameter_array);
void	initialize_grid(int array[4][4]);
void	fill_known_tiles(int array[4][4], int *parameter_array);
void	fill_the_missing_number(int array[4][4]);

void	rush(int argc, char *argv[])
{
	int	parameter_array[16];
	int	array[4][4];
	int	err;
	int	err2;

	err = take_parameters(argv[1], parameter_array);
	if (argc == 2 && err == 0)
	{
		err2 = check_parameters(parameter_array);
		if (err2 == 0)
		{
			initialize_grid(array);
			fill_known_tiles(array, parameter_array);
			fill_the_missing_number(array);
			print_grid(array);
		}
		else
			write(1, "Error: Parámetros no válidos\n", 31);
	}
	else
		write(1, "Error\n", 6);
}
