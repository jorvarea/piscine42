/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:19:29 by jorvarea          #+#    #+#             */
/*   Updated: 2023/07/16 22:15:54 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	conditions_to_fill(int array[4][4], int *parameter_array, int i);

void	fill_known_tiles(int array[4][4], int *parameter_array)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		conditions_to_fill(array, parameter_array, i);
		i++;
	}
}

void	search_row_and_col(int array[4][4], int row, int col,
		int possible_numbers[4])
{
	int	i;

	possible_numbers[0] = 1;
	possible_numbers[1] = 2;
	possible_numbers[2] = 3;
	possible_numbers[3] = 4;
	i = 0;
	while (i < 4)
	{
		if (array[row][i] > 0)
			possible_numbers[array[row][i] - 1] = 0;
		if (array[i][col] > 0)
			possible_numbers[array[i][col] - 1] = 0;
		i++;
	}
}

int	count_possible_numbers(int possible_numbers[4])
{
	int	k;
	int	num;
	int	count;

	k = 0;
	count = 0;
	while (k < 4)
	{
		if (possible_numbers[k] != 0)
		{
			num = possible_numbers[k];
			count++;
		}
		k++;
	}
	if (count == 1)
		return (num);
	else
		return (0);
}

void	fill_the_missing_number(int array[4][4])
{
	int	i;
	int	j;
	int	num;
	int	possible_numbers[4];

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (array[i][j] == 0)
			{
				search_row_and_col(array, i, j, possible_numbers);
				num = count_possible_numbers(possible_numbers);
				if (num != 0)
					array[i][j] = num;
			}
			j++;
		}
		i++;
	}
}
