/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_basic_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:35:49 by svaccaro          #+#    #+#             */
/*   Updated: 2023/07/26 20:58:40 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_basic_functions.h"

void	ft_putchar(char n)
{
	write(1, &n, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		ft_putchar(str[i++]);
}

int	ft_atoi(char *str)
{
	int	counter_sign;
	int	number;
	int	i;

	counter_sign = 0;
	number = 0;
	i = 0;
	while (*(str + i) == ' ' || ((*(str + i) >= 9) && (*(str + i) <= 13)))
		++i;
	while (*(str + i) == '-' || *(str + i) == '+')
	{
		if (*(str + i) == '-')
			++counter_sign;
		++i;
	}
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		number *= 10;
		number += *(str + i) - '0';
		++i;
	}
	if (counter_sign % 2)
		return (-number);
	return (number);
}

char	number_to_char(int n)
{
	char	c;

	c = n + '0';
	return (c);
}

void	ft_putnbr(int nb)
{
	char	c;

	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = 147483648;
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb < 10)
	{
		c = number_to_char(nb);
		ft_putchar(c);
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		c = number_to_char(nb % 10);
		ft_putchar(c);
	}
}
