/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:56:57 by jorvarea          #+#    #+#             */
/*   Updated: 2023/07/24 17:11:06 by jorvarea         ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	int	found;
	int	i;

	found = 0;
	i = 0;
	while (found == 0)
	{
		if (ft_is_prime(nb + i))
			found = 1;
		i++;
	}
	return (nb + i - 1);
}

/*int	main(void)
{
	int	num;

	num = ft_find_next_prime(89);
	printf("%d\n", num);
}*/
