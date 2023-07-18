/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_parameters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 17:21:45 by jorvarea          #+#    #+#             */
/*   Updated: 2023/07/16 17:26:04 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	take_parameters(char *str, int *parameter_array)
{
	int	i;
	int	parameter_count;

	parameter_count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (i % 2 == 0 && str[i] >= '1' && str[i] <= '4')
		{
			parameter_array[parameter_count] = str[i] - '0';
			parameter_count++;
		}
		i++;
	}
	if (parameter_count == 16)
		return (0);
	else
		return (1);
}

int	check_parameters(int *parameter_array)
{
	int	i;
	int	sum;

	i = 0;
	while (i < 4)
	{
		sum = parameter_array[i] + parameter_array[i + 4];
		if (sum < 3 || sum > 5)
			return (1);
		else
			i++;
	}
	while (i >= 8 && i < 12)
	{
		sum = parameter_array[i] + parameter_array[i + 4];
		if (sum < 3 || sum > 5)
			return (1);
		else
			i++;
	}
	return (0);
}
