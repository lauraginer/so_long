/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:50:35 by lginer-m          #+#    #+#             */
/*   Updated: 2024/10/16 21:22:18 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int flood_fill(t_game *game)
{
	char **copy_map;

	copy_map = ft_copy_map(game->map);
	found_player(t_game *game);
	check_ec(t_game	*game);
	
	
	
	
	
}

char	**ft_copy_map(t_game *game) //copiar el mapa en un char **
{
	int 	y;
	
	game->duplicate = (char **)malloc(sizeof(char*) * (game->height + 1));
	if(!game->duplicate)
		return (NULL);
	y = 0;
	while(y < game->height)
	{
		game->duplicate[y] = ft_strdup(game->map[y]); //copiar por cada fila
		if(!game->duplicate[y])
		{
			while(y > 0)
				free(game->duplicate[--y]);
			free(game->duplicate);
			return(NULL);
		}
		y++;
	}
	game->duplicate[y] = NULL;//para indicar en caso de error
	return(game->duplicate);	
}

void	found_player(t_game *game) //desde donde esta la P empezar flood fill
{
	int y;
	int x;

	y = 0;
	while(game->map[y])
	{
		x = 0;
		while(game->map[y][x])
		{
			if(game->map[y][x] == 'P')
			{
				game->map[y] = y;
				game->map[x] = x;
				return;
			}
			x++;
		}
		y++;
	}
	game->y = -1;
	game->x = -1;//para indicar en caso de error
}

int	check_ec(t_game *game)//comprobar que no tienes ni E ni C
{
	int y;
	int x;

	y = 0;
	while(game->map[y])
	{
		x = 0;
		while(game->map[y][x])
		{
			if(game->map[y][x] == 'E' || game->map[y][x] == 'C' || game->map[y][x] == 'P') 
				print_error("Error: Invalid path");
			x++;
		}
		y++;
	}
	return(0);
}

void	free_map(t_game *game)//liberar el mpap en cualquier caso
{
	int	i;
	
	i = 0;
	if(game->duplicate)
	{
		while(i < game->height)
		{
			if(game->duplicate[i])
				free(game->duplicate[i]);
			i++;
		}
		free(game->duplicate);
	}
	return(0);
}
