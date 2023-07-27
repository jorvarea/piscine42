/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:29:38 by jorvarea          #+#    #+#             */
/*   Updated: 2023/07/27 23:11:16 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	num;

	sign = 1;
	num = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (is_space(str[i]))
			i++;
		while (str[i] == '-' || str[i] == '+')
			if (str[i++] == '-')
				sign *= -1;
		while (str[i] >= '0' && str[i] <= '9')
			num = num * 10 + (str[i++] - '0');
		if (num != 0)
			return (num * sign);
		else
			return (0);
		i++;
	}
	return (num * sign);
}

/*int main()
{
	char *str;

	str = "     -----+++++----12341";
	printf("%d\n", ft_atoi(str));
}*/
