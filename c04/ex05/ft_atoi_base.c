/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:35:08 by jorvarea          #+#    #+#             */
/*   Updated: 2023/07/27 23:17:16 by jorvarea         ###   ########.fr       */
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
			else if (is_space(base[i]) || is_space(base[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_handle_spaces(char *str, int i, int *sign)
{
	while (is_space(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			*sign *= -1;
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	base_number;
	int	sign;
	int	digit;
	int	num;

	i = 0;
	while (base[i] != '\0')
		i++;
	base_number = i;
	if (valid_base(base, base_number))
	{
		sign = 1;
		num = 0;
		i = 0;
		while (str[i] != '\0')
		{
			i = ft_handle_spaces(str, i, &sign);
			while (str[i] && !is_space(str[i]) && str[i] != '-'
				&& str[i] != '+')
			{
				digit = ft_char2digit(str[i++], base);
				if (digit != -1)
					num = num * base_number + digit;
				else
					return (0);
			}
			if (num != 0)
				return (num * sign);
			else
				return (0);
			i++;
		}
		return (num * sign);
	}
	else
		return (0);
}

/*int	main(void)
{
	char	*str;
	int		num;
	char	*base;

	base = "0123456789abcdef";
	str = "   --------+- 2a";
	num = ft_atoi_base(str, base);
	printf("%d\n", num);
	return (0);
}*/
