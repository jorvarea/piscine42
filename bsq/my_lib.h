/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:35:40 by svaccaro          #+#    #+#             */
/*   Updated: 2023/07/27 14:35:07 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_LIB_H
# define MY_LIB_H

# include "my_basic_functions.h"
# include "my_basic_functions2.h"
# include <fcntl.h>
# include <stdlib.h>

int	save_map_metadata(t_map *map, int file);
int	check_if_newline(char ch, t_map *map, int *count_row, int *count_col);
int	get_size_map(t_map *map, int file);
int	check_map(t_map *map, char *filename);
int	get_map(char *filename, t_map *map);

#endif /* MY_LIB_H */
