/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:17:58 by lauragm           #+#    #+#             */
/*   Updated: 2024/10/18 13:58:27 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_mlx(t_game *game)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(game->width * PIXEL_SIZE, 
				game->height * PIXEL_SIZE, "so_long", true);
	if(!game->mlx)
		print_error("Error: Failed to initialize MLX");
	create_textures(game);
	create_images(game);
	load_images(game);
	mlx_loop(game->mlx);
}

void	create_textures(t_game *game)
{
	game->txt_player = mlx_load_png("./images/player(2).png");
	if(!game->txt_player)
		print_error("Error: Failed to create the texture of player");
	game->txt_coin= mlx_load_png("./images/coin(2).png");
	if(!game->txt_coin)
		print_error("Error: Failed to create the texture of coin");
	game->txt_wall = mlx_load_png("./images/wall.png");
	if(!game->txt_wall)
		print_error("Error: Failed to create the texture of wall");
	game->txt_floor = mlx_load_png("./images/floor.png");
	if(!game->txt_floor)
		print_error("Error: Failed to create the texture of floor");
	game->txt_exit = mlx_load_png("./images/exit(2).png");
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
