/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_basic_functions2.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:40:41 by jorvarea          #+#    #+#             */
/*   Updated: 2023/07/27 10:52:41 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_BASIC_FUNCTIONS2_H
# define MY_BASIC_FUNCTIONS2_H
# include "my_basic_functions.h"
# include <stdlib.h>

int		check_char(t_map *map, char ch);
int		map_error(void);
int		get_number_rows_and_empty_char(int file, t_map *map, int *count);
void	ft_swap(int *a, int *b);
void	ft_sort_int_tab(int *tab, int size);

#endif