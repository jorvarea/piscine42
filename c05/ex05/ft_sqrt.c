/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:21:24 by jorvarea          #+#    #+#             */
/*   Updated: 2023/07/24 12:34:32 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	n;
	int	half_nb;

	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (0);
	else if (nb == 1)
		return (1);
	half_nb = nb / 2;
	n = 1;
	while (n <= half_nb)
	{
		if (n * n == nb)
			return (n);
		n++;
	}
	return (0);
}

/*int	main(void)
{
	int	num;

	num = ft_sqrt(100000000);
	printf("%d\n", num);
}*/
