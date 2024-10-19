/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:05:56 by lauragm           #+#    #+#             */
/*   Updated: 2024/10/19 17:42:41 by lauragm          ###   ########.fr       */
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
		mlx_image_to_window(game->mlx, game->png_floor, game->x * 128, game-> y * 128);
	}
	if(position_p == 'E')
	{
		printf("Player is on exit. Coins collected: %d, Total coins: %d\n", game->coin, game->total_coins);
		if (game->coin == game->total_coins)
		{
			printf("All coins collected. Calling win_txt.\n");
			win_txt(game);
			mlx_close_window(game->mlx);
			return;
		}
		//printf("%d\n", game->total_coins);
		//printf("%d\n", game->coin);
		game->map[game->y][game->x] = 'E';
	}
	mlx_delete_image(game->mlx, game->png_player);
	game->png_player = mlx_texture_to_image(game->mlx, game->txt_player);
	mlx_image_to_window(game->mlx, game->png_player, game->x * 128, game-> y * 128 );
}	