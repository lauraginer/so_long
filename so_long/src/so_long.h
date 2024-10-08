/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:26:47 by lginer-m          #+#    #+#             */
/*   Updated: 2024/10/09 19:18:56 by lginer-m         ###   ########.fr       */
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
} t_game;

int		check_extension_map(char *str);
int		check_valid_char(t_game *game);
int		check_format(t_game *game);
int		check_walls(t_game *game);
int		check_items(t_game *game);
int		count_lines(char *file);
int		memory_map(t_game *map_struct);
int		fill_map(t_game *map_struct, char *file);
void	print_map(t_game *map_struct);
int		ft_strlen_so_long(char *str);
#endif
