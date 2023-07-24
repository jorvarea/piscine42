/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:29:38 by jorvarea          #+#    #+#             */
/*   Updated: 2023/07/20 21:31:39 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str2num(char *number, int sign, int number_count)
{
	int	num;
	int	k;

	k = 1;
	num = 0;
	while (number_count > 0)
	{
		num = num + (number[number_count - 1] - '0') * k;
		number_count--;
		k *= 10;
	}
	return (sign * num);
}

int	ft_atoi(char *str)
{
	int		i;
	int		j;
	int		sign;
	char	number[30];

	sign = 1;
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			sign *= -1;
		while (str[i] >= '0' && str[i] <= '9')
		{
			number[j] = str[i];
			j++;
			i++;
		}
		if (j > 0)
			return (str2num(number, sign, j));
		i++;
	}
	return (0);
}
