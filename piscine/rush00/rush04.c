/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:02:36 by jorvarea          #+#    #+#             */
/*   Updated: 2023/07/09 21:19:23 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_conditions(int x, int y, int i, int j)
{
	if ((i == 1 && j == 1) || (i == y && j == x && y != 1 && x != 1))
		ft_putchar('A');
	else if ((i == 1 && j == x) || (i == y && j == 1))
		ft_putchar('C');
	else if (i == 1 || i == y)
		ft_putchar('B');
	else if (i != 1 && i != y && (j == 1 || j == x))
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	if (x < 0 || y < 0)
		return ;
	i = 1;
	while (i <= y)
	{
		j = 1;
		while (j <= x)
		{
			ft_conditions(x, y, i, j);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
