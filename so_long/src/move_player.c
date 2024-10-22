/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:05:56 by lauragm           #+#    #+#             */
/*   Updated: 2024/10/22 21:51:32 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game)
{
	char	position_p;

	position_p = game->map[game->y][game->x];
	if (position_p == 'C')
	{
		game->map[game->y][game->x] = '0';
		mlx_image_to_window(game->mlx, game->png_floor, game->x * 128, game->y
			* 128);
	}
	if (position_p == 'E')
	{
		if (game->total_coins == 0)
		{
			win_txt(game);
			mlx_close_window(game->mlx);
			return ;
		}
		game->map[game->y][game->x] = 'E';
	}
	mlx_delete_image(game->mlx, game->png_player);
	game->png_player = mlx_texture_to_image(game->mlx, game->txt_player);
	mlx_image_to_window(game->mlx, game->png_player, game->x * 128, game->y
		* 128);
}
