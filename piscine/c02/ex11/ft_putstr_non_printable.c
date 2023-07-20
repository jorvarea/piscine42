/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:03:05 by jorvarea          #+#    #+#             */
/*   Updated: 2023/07/18 19:37:29 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
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

void	dec2hex(int dec, char *hex)
{
	int	i;
	int	quotient;
	int	remainder;

	i = 0;
	quotient = dec;
	while (quotient != 0)
	{
		remainder = quotient % 16;
		quotient = quotient / 16;
		hex[i] = "0123456789abcdef"[remainder];
		i++;
	}
	ft_rev_char_str(hex, i);
	hex[i] = '\0';
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	char			hex[20];
	unsigned char	c;

	i = 0;
	c = str[i];
	while (c != '\0')
	{
		if (c < 32 || c >= 127)
		{
			dec2hex(c, hex);
			write(1, "\\", 1);
			if (c < 16)
				write(1, "0", 1);
			ft_putstr(hex);
		}
		else
			write(1, &c, 1);
		i++;
		c = str[i];
	}
}
