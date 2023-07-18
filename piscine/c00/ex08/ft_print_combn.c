/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:09:31 by jorvarea          #+#    #+#             */
/*   Updated: 2023/07/07 11:19:10 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_set_initial_values(int digits[10], int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		digits[i] = i;
		i++;
	}
}

void	ft_show_current_comb(int digits[10], int n)
{
	int	i;
	int	digit;

	i = 0;
	while (i < n)
	{
		digit = '0' + digits[i];
		write(1, &digit, 1);
		i++;
	}
	write(1, ", ", 2);
}

void	ft_gen_new_comb(int digits[10], int n)
{
	int	i;

	i = n - 1;
	while (i >= 0)
	{
		if (digits[i] < 9)
		{
			digits[i]++;
			return ;
		}
		else
		{
			if (i != 0)
			{
				digits[i] = 0;
				i--;
			}
			else
				return ;
		}
	}
}

void	ft_print_combn(int n)
{
	int		digits[10];
	char	digit;

	ft_set_initial_values(digits, n);
	while (digits[0] <= (9 - n + 1))
	{
		ft_show_current_comb(digits, n);
		ft_gen_new_comb(digits, n);
	}
}

int	main(void)
{
	int	n;

	n = 2;
	ft_print_combn(2);
	return (0);
}
