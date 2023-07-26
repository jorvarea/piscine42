/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:21:51 by jorvarea          #+#    #+#             */
/*   Updated: 2023/07/26 20:29:16 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_swap_str(char **str1, char **str2)
{
	char	*swap;

	swap = *str1;
	*str1 = *str2;
	*str2 = swap;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

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

void	ft_sort_str_tab(char **tab, int size)
{
	int	i;
	int	j;
	int	min_index;

	i = 0;
	j = 0;
	while (i < size)
	{
		min_index = i;
		j = i + 1;
		while (j < size)
		{
			if (ft_strcmp(tab[j], tab[min_index]) < 0)
				min_index = j;
			j++;
		}
		if (min_index != i)
			ft_swap_str(&tab[i], &tab[min_index]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	char	*parametros[100];

	i = 0;
	while (i < 100)
		parametros[i++] = NULL;
	i = 1;
	while (i < argc)
	{
		parametros[i - 1] = argv[i];
		i++;
	}
	ft_sort_str_tab(parametros, argc - 1);
	i = 1;
	while (i < argc)
	{
		ft_putstr(parametros[i - 1]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
