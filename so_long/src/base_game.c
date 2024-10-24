/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:17:58 by lauragm           #+#    #+#             */
/*   Updated: 2024/10/22 21:28:16 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_mlx(t_game *game)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(game->width * PIXEL_SIZE,
			game->height * PIXEL_SIZE, "so_long", true);
	if (!game->mlx)
		print_error("Error: Failed to initialize MLX", game);
	create_textures(game);
	create_images(game);
	load_images(game);
	mlx_key_hook(game->mlx, &keymoves, game);
	mlx_loop(game->mlx);
}

void	create_textures(t_game *game)
{
	game->txt_player = mlx_load_png("./images/player(2).png");
	if (!game->txt_player)
		print_error("Error: Failed to create the texture of player", game);
	game->txt_coin = mlx_load_png("./images/coin(2).png");
	if (!game->txt_coin)
		print_error("Error: Failed to create the texture of coin", game);
	game->txt_wall = mlx_load_png("./images/wall.png");
	if (!game->txt_wall)
		print_error("Error: Failed to create the texture of wall", game);
	game->txt_floor = mlx_load_png("./images/floor.png");
	if (!game->txt_floor)
		print_error("Error: Failed to create the texture of floor", game);
	game->txt_exit = mlx_load_png("./images/exit(2).png");
	if (!game->txt_exit)
		print_error("Error: Failed to create the texture of exit", game);
}

void	create_images(t_game *game)
{
	game->png_player = mlx_texture_to_image(game->mlx, game->txt_player);
	if (!game->png_player)
		print_error("Error: Failed to create the image of player", game);
	game->png_coin = mlx_texture_to_image(game->mlx, game->txt_coin);
	if (!game->png_coin)
		print_error("Error: Failed to create the image of coin", game);
	game->png_wall = mlx_texture_to_image(game->mlx, game->txt_wall);
	if (!game->png_wall)
		print_error("Error: Failed to create the image of wall", game);
	game->png_floor = mlx_texture_to_image(game->mlx, game->txt_floor);
	if (!game->png_floor)
		print_error("Error: Error: Failed to create the image of floor", game);
	game->png_exit = mlx_texture_to_image(game->mlx, game->txt_exit);
	if (!game->png_exit)
		print_error("Error: Failed to create the image of exit", game);
}

void	load_images(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == '1')
				mlx_image_to_window(game->mlx, game->png_wall, x * PIXEL_SIZE,
					y * PIXEL_SIZE);
			else if (game->map[y][x] == '0')
				mlx_image_to_window(game->mlx, game->png_floor, x * PIXEL_SIZE,
					y * PIXEL_SIZE);
			else if (game->map[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->png_coin, x * PIXEL_SIZE,
					y * PIXEL_SIZE);
			load_second_images(game);
			x++;
		}
		y++;
	}
}

void	load_second_images(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->png_exit, x * PIXEL_SIZE,
					y * PIXEL_SIZE);
			else if (game->map[y][x] == 'P')
			{
				mlx_image_to_window(game->mlx, game->png_floor, x * PIXEL_SIZE,
					y * PIXEL_SIZE);
				mlx_image_to_window(game->mlx, game->png_player, x * PIXEL_SIZE,
					y * PIXEL_SIZE);
			}
			x++;
		}
		y++;
	}
}
