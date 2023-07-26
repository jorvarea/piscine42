/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:35:40 by svaccaro          #+#    #+#             */
/*   Updated: 2023/07/26 21:48:44 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_LIB_H
# define MY_LIB_H

# include "my_basic_functions.h"
# include "my_basic_functions2.h"
# include <fcntl.h>
# include <stdlib.h>

int	check_char(t_map *map, char ch);
int	save_map_metadata(t_map *map, int file);
int	get_size_map(t_map *map, int file);
int	check_map(t_map *map, char *filename);
int	get_map(char *filename, t_map *map);
int	get_number_rows_and_empty_char(int file, t_map *map, int *count);

#endif /* MY_LIB_H */
