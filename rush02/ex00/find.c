/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 20:02:08 by jorvarea          #+#    #+#             */
/*   Updated: 2023/07/23 21:54:04 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

typedef struct t_NumberName
{
	int		number;
	char	name[30];
}			t_NumberName;

typedef struct t_counters
{
	int		i;
	int		k;
}			t_counters;

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

int	ft_find_number(t_NumberName *dict, int *num, int size_dict)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size_dict)
	{
		if (dict[++i].number == *num && *num != 0)
		{
			if (*num == 100 || *num == 1000 || *num == 1000000
				|| *num == 1000000000)
				write(1, "one ", 4);
			ft_putstr(dict[i].name);
			return (1);
		}
	}
	if (*num < 100)
	{
		temp = *num / 10 * 10;
		ft_find_number(dict, &temp, size_dict);
		write(1, "-", 1);
		temp = *num % 10;
		ft_find_number(dict, &temp, size_dict);
		return (1);
	}
	return (0);
}

void	ft_actually_write_number(t_NumberName *dict, int *num, int size_dict,
		t_counters cont)
{
	int	temp;

	temp = *num / cont.k;
	ft_find_number(dict, &temp, size_dict);
	write(1, " ", 1);
	ft_putstr(dict[cont.i].name);
	if (cont.k == 1000 || cont.k == 1000000 || cont.k == 1000000000)
		write(1, ",", 1);
	write(1, " ", 1);
	if (*num > 99 && *num % 100 != 0 && cont.k == 100)
		write(1, "and ", 4);
	*num = *num - cont.k * (*num / cont.k);
}

void	ft_find_out_number(t_NumberName *dict, int *num, int size_dict)
{
	t_counters	cont;

	cont.k = 1000000000;
	while (cont.k > *num)
		cont.k = cont.k / 10;
	while (cont.k >= 1)
	{
		cont.i = 0;
		while (cont.i < size_dict)
		{
			if (dict[++cont.i].number == cont.k)
			{
				if (ft_find_number(dict, num, size_dict) != 1)
					ft_actually_write_number(dict, num, size_dict, cont);
				else
					return ;
			}
		}
		cont.k = cont.k / 10;
	}
}

void	ft_write_number(t_NumberName *dict, int *num, int size_dict)
{
	if (ft_find_number(dict, num, size_dict) == 1)
		return ;
	else
		ft_find_out_number(dict, num, size_dict);
}
