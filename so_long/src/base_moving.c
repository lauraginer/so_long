/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_moving.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:43:57 by lginer-m          #+#    #+#             */
/*   Updated: 2024/10/18 13:48:43 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	transitable_box( t_game *game, int y, int x) //verifica si se puede mover una casilla en el mapa
{
	if(game->map[y][x] != '1') //si la casilla es transitable(no es un muro), actualiza la posicion y retorna 1.
	{
		game->y = y;
		game->x = x;
		return(1);
	}
	return (0);
}

int	keymove_w(t_game *game)
{
	int	y;
	int	x;

	y = game->y;
	x = game->x;
	if(mlx_is_key_down(game->mlx, MLX_KEY_W) && transitable_box(game, y - 1, x))
	{
		game->png_player->instances[0].y -= 128; //mueve el jugador hacia arriba en 128 unidades(pixeles)
		game->count++;
		printf("Move count: %d\n", game->count);
	}
	return(-1);
}

int	keymove_a(t_game *game)
{
	int	y;
	int	x;

	y = game->y;
	x = game->x;
	if(mlx_is_key_down(game->mlx, MLX_KEY_A) && transitable_box(game, y, x - 1))
	{
		game->png_player->instances[0].x -= 128;
		game->count++;
		printf("Move count: %d\n", game->count);
	}
	return(-1);
}

int	keymove_s(t_game *game)
{
	int	y;
	int	x;

	y = game->y;
	x = game->x;
	if(mlx_is_key_down(game->mlx, MLX_KEY_S) && transitable_box(game, y + 1, x))
	{
		game->png_player->instances[0].y += 128;
		game->count++;
		printf("Move count: %d\n", game->count);
	}
	return(-1);
}

int	keymove_d(t_game *game)
{
	int	y;
	int	x;

	y = game->y;
	x = game->x;
	if(mlx_is_key_down(game->mlx, MLX_KEY_D) && transitable_box(game, y, x + 1))
	{
		game->png_player->instances[0].x += 128;
		game->count++;
		printf("Move count: %d\n", game->count);
	}
	return(-1);
}
