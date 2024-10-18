/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:05:56 by lauragm           #+#    #+#             */
/*   Updated: 2024/10/18 19:53:59 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game)
{
	char	position_p;

	position_p = game->map[game->y][game->x];
	if(position_p == 'C')
	{
		game->coin++;
		game->map[game->y][game->x] = '0'; //se actualiza a 0 cuando ya ha movido la moneda
		
	}
	if(position_p == 'E')
	{
		if (game->coin == game->total_coins)
			win_txt(game);
		else
			game->map[game->y][game->x] = 'E';
	}
	else
		game->map[game->y][game->x] = 'P';

	mlx_image_to_window(game->mlx, game->png_floor, game->x * 128, game-> y * 128);
	mlx_delete_image(game->mlx, game->png_player);
	game->png_player = mlx_texture_to_image(game->mlx, game->txt_player);
	mlx_image_to_window(game->mlx, game->png_player, game->x * 128, game-> y * 128 );
}
