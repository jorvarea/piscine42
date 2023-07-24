/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setdict.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:40:14 by jorvarea          #+#    #+#             */
/*   Updated: 2023/07/23 21:47:37 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct t_NumberName
{
	int			number;
	char		name[30];
}				t_NumberName;

typedef struct t_counters
{
	int			i;
	int			j;
}				t_counters;

int	str2unint(char *number, int number_count)
{
	int	num;
	int	k;

	k = 1;
	num = 0;
	while (number_count > 0)
	{
		num = num + (number[number_count - 1] - '0') * k;
		number_count--;
		k *= 10;
	}
	return (num);
}

int	ft_count_newlines(char *text, ssize_t bytes_read)
{
	int	newline_count;
	int	i;

	newline_count = 0;
	i = 0;
	while (i < bytes_read)
	{
		if (text[i] == '\n')
			newline_count++;
		i++;
	}
	return (newline_count);
}

int	ft_extract_number_and_text(char *text, t_NumberName *dict, char *number,
		t_counters cont)
{
	int	k;
	int	l;

	while (text[cont.j] != '\n' && text[cont.j] != 3)
	{
		k = 0;
		while (text[cont.j] >= '0' && text[cont.j] <= '9')
			number[k++] = text[cont.j++];
		if (k != 0)
			dict[cont.i].number = str2unint(number, k);
		l = 0;
		while ((text[cont.j] > 32 && text[cont.j] < 127 && text[cont.j] != ':')
			|| text[cont.j] == ' ')
			dict[cont.i].name[l++] = text[cont.j++];
		if (l != 0)
			dict[cont.i].name[l] = '\0';
		if (l == 0 && k == 0)
			return (cont.j);
		if (text[cont.j] == ':' || text[cont.j] == ' ')
			cont.j++;
	}
	return (cont.j);
}

void	ft_fill_dict(char *text, t_NumberName *dict, int *newline_count)
{
	char		number[10];
	t_counters	cont;

	cont.i = 0;
	cont.j = 0;
	while (cont.i < *newline_count)
	{
		cont.j = ft_extract_number_and_text(text, dict, number, cont);
		cont.i++;
		cont.j++;
	}
}

t_NumberName	*setdict(char *filename, int *newline_count)
{
	int				file;
	ssize_t			bytes_read;
	char			text[500];
	t_NumberName	*dict;

	file = open(filename, O_RDONLY);
	if (file == -1)
	{
		write(1, "Dict error\n", 11);
		return (0);
	}
	bytes_read = read(file, text, sizeof(text));
	*newline_count = ft_count_newlines(text, bytes_read);
	dict = malloc(*newline_count * sizeof(t_NumberName));
	if (dict != NULL)
		ft_fill_dict(text, dict, newline_count);
	close(file);
	return (dict);
}
