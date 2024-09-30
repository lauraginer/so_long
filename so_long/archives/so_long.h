/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:26:47 by lginer-m          #+#    #+#             */
/*   Updated: 2024/09/30 19:27:37 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
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
	int wall;
	int	x;
	int y;
	char **map;
} t_game














#endif
