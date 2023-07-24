/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:05:17 by jorvarea          #+#    #+#             */
/*   Updated: 2023/07/24 11:18:33 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	factorial;

	if (nb == 0 || nb == 1)
		return (1);
	else if (nb < 0)
		return (0);
	else
	{
		factorial = nb;
		while (nb > 1)
		{
			factorial = factorial * (nb - 1);
			nb = nb - 1;
		}
		return (factorial);
	}
}

/*int	main(int argc, char **argv)
{
	int	num;

	num = ft_iterative_factorial(argv[1][0] - '0');
	printf("%d\n", num);
}*/
