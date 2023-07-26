/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_basic_functions.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaccaro <svaccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:35:46 by svaccaro          #+#    #+#             */
/*   Updated: 2023/07/26 23:15:50 by svaccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_BASIC_FUNCTIONS_H
# define MY_BASIC_FUNCTIONS_H
# include <unistd.h>

typedef struct s_map
{
	int		total_rows;
	int		total_columns;
	char	**map;
	char	empty;
	char	obstacle;
	char	fill;
}			t_map;

typedef struct s_pos
{
	int		row_pos;
	int		col_pos;
}			t_pos;

void		ft_putchar(char n);
void		ft_putstr(char *str);
int			ft_atoi(char *str);
char		number_to_char(int n);
void		ft_putnbr(int nb);

#endif