/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lib2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaccaro <svaccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:35:40 by svaccaro          #+#    #+#             */
/*   Updated: 2023/07/26 22:59:56 by svaccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_LIB2_H
# define MY_LIB2_H

# include "my_basic_functions.h"
# include "my_lib.h"

void	print_map(t_map map);
t_pos	*get_obstacle_pos(t_map *map);
int get_biggest_size();
void	find_biggest_square(t_map *map);

#endif /* MY_LIB2_H */
