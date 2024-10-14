/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_moving.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:43:57 by lginer-m          #+#    #+#             */
/*   Updated: 2024/10/14 22:17:03 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* typedef struct mlx_key_data_t {
    int key;       // Código de la tecla presionada
    int action;    // Acción realizada (presionada, liberada, etc.)
    int mods;      // Modificadores (Shift, Ctrl, etc.)
} mlx_key_data_t; */

int	transitable_box( t_game *game, int y, int x) //verifica si se puede mover una casilla en el mapa
{
	//printf("%d %d", game->x, game->y);
	if(game->map[y][x] != '1') //si la casilla es transitable(no es un muro), actualiza la posicion y retorna 1.
	{
		game->y = y;
		game->x = x;
		return(1);
	}
	else
	{
		perror("Error: Non transitable box");
		return(-1);
	}
}

void	keymove_w(t_game *game, mlx_key_data_t keydata, void *param)
{
	int y;
	int	x;

	game->game = param;
	y = game->y;
	x = game->x;
	
	
}