/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:35:08 by jorvarea          #+#    #+#             */
/*   Updated: 2023/07/25 14:31:50 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	valid_base(char *base, int base_number)
{
	int	i;
	int	j;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	i = 0;
	while (i < base_number)
	{
		j = i + 1;
		while (j < base_number)
		{
			if (base[i] == base[j])
				return (0);
			else if (base[i] == '-' || base[i] == '+' || base[j] == '-'
				|| base[j] == '+')
				return (0);
			else if (!(base[i] > 31 && base[i] < 127 && base[j] > 31
					&& base[j] < 127))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_char2digit(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_atoi_str(char *str, char *number, char *base)
{
	int	i;
	int	j;
	int	digit;

	i = 0;
	j = 1;
	number[0] = '+';
	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '-' && number[0] != '-')
			number[0] = '-';
		else if (str[i] == '-' && number[0] == '-')
			number[0] = '+';
		digit = ft_char2digit(str[i], base);
		if (digit != -1)
		{
			number[j] = digit + '0';
			j++;
		}
		if (j > 0)
			number[j] = '\0';
		i++;
	}
}

int	ft_number2dec(char *number, int base_number)
{
	int	sign;
	int	i;
	int	num;
	int	k;

	if (number[0] == '+')
		sign = 1;
	else
		sign = -1;
	i = 0;
	while (number[i] != '\0')
		i++;
	num = 0;
	k = 1;
	i = i - 1;
	while (i > 0)
	{
		num = num + (number[i] - '0') * k;
		k *= base_number;
		i--;
	}
	return (num * sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int		base_number;
	int		i;
	char	number[30];

	i = 0;
	while (base[i] != '\0')
		i++;
	base_number = i;
	ft_atoi_str(str, number, base);
	if (valid_base(base, base_number) == 1)
		return (ft_number2dec(number, base_number));
	else
		return (0);
}

/*int	main(void)
{
	char	*str;
	int		num;
	char	*base;

	base = "0123456789abcdef";
	str = " \f-80000000";
	num = ft_atoi_base(str, base);
	printf("%d\n", num);
	return (0);
}*/
