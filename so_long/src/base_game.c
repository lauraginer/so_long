/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:17:58 by lauragm           #+#    #+#             */
/*   Updated: 2024/10/12 20:02:46 by lauragm          ###   ########.fr       */
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
		return (-1);
	}
	game->win = mlx_new_window(mlx, width, height, "Ventana MLX Básica");
	if(!win)
	{
		perror("Error: Failed to reate window");
		return (-1);		
	}
	mlx_loop(mlx);
}

void	create_textures(t_game *game)
{
	game->txt_player = mlx_load_png("./images/player.png");
	if(!game->txt_player)
	{
		perror("Error: Failed to create the texture of player");
		return;
	}
}

void	create_images(t_game *game) // la funcion utiliza mlx_texture_to_image para convertir texturas a imagenes
{
	game->png_player = mlx_texture_to_image(game->mlx, game->txt_player); //la funcion toma como valores el mlx(el init de la mlx) y la textura zorrespondiente
	if(!game->png_player)
	{
		perror("Error: Failed to create the image of player");
		return;
	}
	game->png_coin = mlx_texture_to_image(game->mlx, game->txt_coin);
	if(!game->png_coin)
	{
		perror("Error: Failed to create the image of coin");
		return;
	}
	game->png_wall = mlx_texture_to_image(game->mlx, game->txt_wall);
	if(!game->png_wall)
	{
		perror("Error: Failed to create the image of wall");
		return;
	}
	game->png_floor = mlx_texture_to_image(game->mlx, game->txt_floor);
	if(!game->png_floor)
	{
		perror("Error: Failed to create the image of floor");
		return;
	}
	game->png_exit = mlx_texture_to_image(game->mlx, game->txt_exit);
	if(!game->png_exit)
	{
		perror("Error: Failed to create the image of exit");
		return;
	}
}

