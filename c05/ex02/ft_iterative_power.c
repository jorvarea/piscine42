/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:31:44 by jorvarea          #+#    #+#             */
/*   Updated: 2023/07/24 12:00:02 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	num;

	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
	{
		i = 1;
		num = nb;
		while (i < power)
		{
			num = num * nb;
			i++;
		}
	}
	return (num);
}

/*int	main(int argc, char **argv)
{
	int	num;

	num = ft_iterative_power(10, 1);
	printf("%d\n", num);
}*/
