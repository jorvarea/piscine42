/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:21:24 by jorvarea          #+#    #+#             */
/*   Updated: 2023/07/26 12:16:01 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

int	ft_sqrt(int nb)
{
	int	n;
	int	half_nb;

	if (nb <= 0)
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

	num = ft_sqrt(INT_MAX);
	printf("%d\n", num);
}*/
