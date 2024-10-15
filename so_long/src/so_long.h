/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:26:47 by lginer-m          #+#    #+#             */
/*   Updated: 2024/10/15 20:58:07 by lginer-m         ###   ########.fr       */
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
	int		height;
	int		width;
	int		coins;
	int		player;
	int		exit;
	int		wall;
	int		x;
	int		y;
	char	**map;
	char	**duplicate;
	void	*win;
	mlx_t	*mlx;
	mlx_image_t	*png_player;
	mlx_image_t	*png_coin;
	mlx_image_t	*png_exit;
	mlx_image_t	*png_wall;
	mlx_image_t	*png_floor;
	mlx_texture_t	*txt_player;
	mlx_texture_t	*txt_coin;
	mlx_texture_t	*txt_exit;
	mlx_texture_t	*txt_wall;
	mlx_texture_t	*txt_floor;
	
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
void	print_error(char	*msg);
void	start_mlx(t_game *game);
void	create_textures(t_game *game);
void	create_images(t_game *game);
void	load_images(t_game *game);
int		ft_strlen_so_long(char *str);
#endif
