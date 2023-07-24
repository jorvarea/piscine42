/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:13:36 by iballest          #+#    #+#             */
/*   Updated: 2023/07/23 21:15:34 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct t_NumberName
{
	int			number;
	char		name[30];
}				t_NumberName;

t_NumberName	*setdict(char *filename, int *newline_count);
int				ft_atoi(char *str);
void			ft_stratoi(char *str);
void			ft_write_number(t_NumberName *dict, int *num, int size_dict);

void	ft_rush(t_NumberName *dict, char *filename, int newline_count,
		char *argv)
{
	int	num;
	int	j;

	j = 0;
	num = 0;
	dict = setdict(filename, &newline_count);
	if (dict != NULL)
	{
		while (j < newline_count)
			ft_stratoi(dict[j++].name);
		num = ft_atoi(argv);
		ft_write_number(dict, &num, newline_count);
		free(dict);
	}
	else
		write(1, "Error: Memory is full\n", 22);
}

int	main(int argc, char **argv)
{
	char			*filename;
	t_NumberName	*dict;
	int				newline_count;

	newline_count = 0;
	dict = NULL;
	if (argc == 2)
		filename = "numbers.dict";
	else if (argc == 3)
		filename = argv[1];
	if (argc == 2 || argc == 3)
	{
		if (ft_atoi(argv[argc - 1]) >= 0)
			ft_rush(dict, filename, newline_count, argv[argc - 1]);
		else
			write(1, "Error\n", 5);
	}
	else
		write(1, "Invalid arguments.\n", 19);
	return (0);
}
