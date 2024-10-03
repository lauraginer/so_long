/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:26:47 by lginer-m          #+#    #+#             */
/*   Updated: 2024/10/03 13:45:16 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../Libft/libft.h"
#include "get_next_line_bonus.h"
#include "../MLX42/include/MLX42/MLX42.h"

# define PIXEL_SIZE 128

typedef struct s_game
{
	int height;
	int width;
	int coins;
	int	total_coins;
	int player;
	int	exit;
	int wall;
	int	x;
	int y;
	char **map;
	int	num_lines;
} t_game

int		ft_check_line_map(int fd);
int		ft_check_extension_map(char *str);
int		ft_count_lines(char *file);
int		memory_map(t_game *map_struct);
int		fill_map(t_game *map_struct, char *file);
void	print_map(t_game *map_struct);

#endif
