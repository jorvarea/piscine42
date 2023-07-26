/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:32:59 by jorvarea          #+#    #+#             */
/*   Updated: 2023/07/25 14:31:33 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stddef.h>
#include <unistd.h>

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

void	ft_rev_char_str(char *str, int size)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = size - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

void	ft_write_number(int nbr, char *base, int base_number)
{
	int		i;
	int		quotient;
	int		remainder;
	char	number[30];

	i = 0;
	quotient = nbr;
	while (quotient != 0)
	{
		remainder = quotient % base_number;
		quotient = quotient / base_number;
		number[i++] = base[remainder];
	}
	ft_rev_char_str(number, i);
	number[i] = '\0';
	i = 0;
	while (number[i] != '\0')
	{
		write(1, &number[i], 1);
		i++;
	}
}

void	ft_putnbr_base_long(long nbr, char *base, int base_number)
{
	int		i;
	long	quotient;
	long	remainder;
	char	number[30];

	i = 0;
	quotient = nbr;
	while (quotient != 0)
	{
		remainder = quotient % base_number;
		quotient = quotient / base_number;
		number[i++] = base[remainder];
	}
	ft_rev_char_str(number, i);
	number[i] = '\0';
	i = 0;
	while (number[i] != '\0')
	{
		write(1, &number[i], 1);
		i++;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_number;
	int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	base_number = i;
	if (valid_base(base, base_number))
	{
		if (nbr == 0)
			write(1, "0", 1);
		else if (nbr == -2147483648)
		{
			write(1, "-", 1);
			ft_putnbr_base_long(-(long)nbr, base, base_number);
		}
		else if (nbr < 0)
		{
			write(1, "-", 1);
			nbr = -nbr;
			ft_write_number(nbr, base, base_number);
		}
		else
			ft_write_number(nbr, base, base_number);
	}
}

/*int	main(void)
{
	int		nbr;
	char	*base;

	base = "0123456789abcdef";
	nbr = 42;
	ft_putnbr_base(nbr, base);
}*/
