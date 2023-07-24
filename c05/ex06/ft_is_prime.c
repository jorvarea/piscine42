/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:35:42 by jorvarea          #+#    #+#             */
/*   Updated: 2023/07/24 12:55:57 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	n;
	int	half_nb;

	if (nb < 0)
		return (0);
	else if (nb == 0 || nb == 1)
		return (0);
	n = 2;
	half_nb = nb / 2.0;
	while (n <= half_nb)
	{
		if (nb % n == 0)
			return (0);
		n++;
	}
	return (1);
}

/*int	main(void)
{
	int	num;

	num = ft_is_prime(5);
	printf("%d\n", num);
}*/
