/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:50:35 by lginer-m          #+#    #+#             */
/*   Updated: 2024/10/15 20:59:14 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int flood_fill(t_game *game)
{
	char **copy_map;

	copy_map = ft_copy_map(game->map);
	//copiar el mapa en un char **
	// desde donde esta la P empezar flood fill
	// comprobar que no tienes ni E ni C
	//liberar el mpap en cualquier caso
}

char	**ft_copy_map(t_game *game)
{
	int 	y;
	int 	x;
	
	game->duplicate = (char **)malloc(sizeof(char*) * (game->height + 1));
	if(!game->duplicate)
		return (NULL);
	y = 0;
	while(game->map[y])
	{
		game->duplicate[y] = (char *)malloc(sizeof(char) * (strlen(game->map[y]) + 1));
		if (!game->duplicate[y])
		{
			while(y > 0)
				free(game->duplicate[--y]);
			free(game->duplicate);
			return(NULL);
		}
		x = 0;
		while(game->map[y][x])
		{
			game->duplicate[y][x] = game->map[y][x];
			x++;
		}
	}
	return(game->duplicate);	
}
