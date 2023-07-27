/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lib2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:35:40 by svaccaro          #+#    #+#             */
/*   Updated: 2023/07/27 14:39:14 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_LIB2_H
# define MY_LIB2_H

# include "my_basic_functions.h"
# include "my_basic_functions2.h"
# include "my_basic_functions3.h"
# include "my_lib.h"

int	get_dist_row(t_map *map, int **dist_row);
int	get_dist_col(t_map *map, int **dist_col);
int	get_common_max_posible(t_map *map, int *dist_row, int *dist_col);
int	is_size_possible_row(t_map *map, int size_to_try, int *dist_row);
int	is_size_possible_col(t_map *map, int size_to_try, int *dist_col);

#endif /* MY_LIB2_H */