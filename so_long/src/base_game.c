/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:17:58 by lauragm           #+#    #+#             */
/*   Updated: 2024/10/14 20:21:56 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_mlx(t_game *game)
{
	game->width = 800;
	game->height = 600;

	game->mlx = mlx_init()
	if(!mlx)
	{
		perror("Error: Failed to initialize MLX");
		return(-1);
	}
	game->win = mlx_new_window(mlx, width, height, "Ventana MLX Básica");
	if(!win)
	{
		perror("Error: Failed to reate window");
		return(-1);		
	}
	mlx_loop(mlx);
}

void	create_textures(t_game *game)
{
	game->txt_player = mlx_load_png("./images/player.png");
	if(!game->txt_player)
		print_error("Error: Failed to create the texture of player");
	game->txt_coin= mlx_load_png("./images/coin.png");
	if(!game->txt_coin)
		print_error("Error: Failed to create the texture of coin");
	game->txt_wall = mlx_load_png("./images/wall.png");
	if(!game->txt_wall)
		print_error("Error: Failed to create the texture of wall");
	game->txt_floor = mlx_load_png("./images/floor.png");
	if(!game->txt_floor)
		print_error("Error: Failed to create the texture of floor");
	game->txt_exit = mlx_load_png("./images/exit.png");
	if(!game->txt_exit)
		print_error("Error: Failed to create the texture of exit");
}

void	create_images(t_game *game) // la funcion utiliza mlx_texture_to_image para convertir texturas a imagenes
{
	game->png_player = mlx_texture_to_image(game->mlx, game->txt_player); //la funcion toma como valores el mlx(el init de la mlx) y la textura correspondiente
	if(!game->png_player)
		print_error("Error: Failed to create the image of player");
	game->png_coin = mlx_texture_to_image(game->mlx, game->txt_coin);
	if(!game->png_coin)
		print_error("Error: Failed to create the image of coin");
	game->png_wall = mlx_texture_to_image(game->mlx, game->txt_wall);
	if(!game->png_wall)
		print_error("Error: Failed to create the image of wall");
	game->png_floor = mlx_texture_to_image(game->mlx, game->txt_floor);
	if(!game->png_floor)
		print_error("Error: Error: Failed to create the image of floor");
	game->png_exit = mlx_texture_to_image(game->mlx, game->txt_exit);
	if(!game->png_exit)
		print_error("Error: Failed to create the image of exit");
}

void	load_images(t_game *game) //la funcion de la mlx dibuja una imagen
{
	int	y;
	int x;

	y = 0;
	while(y < game->height)
	{
		x = 0;
		while(x < game->width)
		{
			if(game->map[y][x] == '1')
				mlx_image_to_window(game->mlx, game->png_wall, x * PIXEL_SIZE, y * PIXEL_SIZE);
			else if(game->map[y][x] == '0')
				mlx_image_to_window(game->mlx, game->png_floor, x * PIXEL_SIZE, y * PIXEL_SIZE);
			else if(game->map[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->png_coin, x * PIXEL_SIZE, y * PIXEL_SIZE);
			else if(game->map[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->png_exit, x * PIXEL_SIZE, y * PIXEL_SIZE);
			else if(game->map[y][x] == 'P')
				mlx_image_to_window(game->mlx, game->png_player, x * PIXEL_SIZE, y * PIXEL_SIZE);
			x++;
		}
		y++;
	}
}
