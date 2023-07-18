/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 17:21:35 by jorvarea          #+#    #+#             */
/*   Updated: 2023/07/17 17:03:54 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fill_the_ones(int array[4][4], int i)
{
	if (i < 4)
		array[0][i] = 4;
	else if (i >= 4 && i < 8)
		array[3][i - 4] = 4;
	else if (i >= 8 && i < 12)
		array[i - 8][0] = 4;
	else if (i >= 12)
		array[i - 12][3] = 4;
}

void	fill_the_fours(int array[4][4], int i)
{
	int	k;

	k = 0;
	while (k < 4)
	{
		if (i < 4)
			array[k][i] = k + 1;
		else if (i >= 4 && i < 8)
			array[3 - k][i - 4] = k + 1;
		else if (i >= 8 && i < 12)
			array[i - 8][k] = k + 1;
		else if (i >= 12)
			array[i - 12][3 - k] = k + 1;
		k++;
	}
}

void	fill_the_21(int array[4][4], int i)
{
	if (i < 4)
		array[0][i] = 3;
	else if (i >= 4 && i < 8)
		array[3][i - 4] = 3;
	else if (i >= 8 && i < 12)
		array[i - 8][0] = 3;
	else if (i >= 12)
		array[i - 12][3] = 3;
}

void	fill_the_23(int array[4][4], int i)
{
	if (i < 4)
		array[1][i] = 4;
	else if (i >= 4 && i < 8)
		array[2][i - 4] = 4;
	else if (i >= 8 && i < 12)
		array[i - 8][1] = 4;
	else if (i >= 12)
		array[i - 12][2] = 4;
}

void	conditions_to_fill(int array[4][4], int *parameter_array, int i)
{
	if (parameter_array[i] == 1)
		fill_the_ones(array, i);
	else if (parameter_array[i] == 4)
		fill_the_fours(array, i);
	else if (parameter_array[i] == 2)
	{
		if (i < 4 || (i >= 8 && i < 12))
		{
			if (parameter_array[i + 4] == 1)
				fill_the_21(array, i);
			else if (parameter_array[i + 4] == 3)
				fill_the_23(array, i);
		}
		else
		{
			if (parameter_array[i - 4] == 1)
				fill_the_21(array, i);
			else if (parameter_array[i - 4] == 3)
				fill_the_23(array, i);
		}
	}
}
