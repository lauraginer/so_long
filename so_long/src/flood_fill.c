/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:50:35 by lginer-m          #+#    #+#             */
/*   Updated: 2024/10/19 18:59:26 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **copy, int y, int x)
{
	if(copy[y][x] != '1')
	{
		copy[y][x] = '1';
		flood_fill(copy, y - 1, x);
		flood_fill(copy, y + 1, x);
		flood_fill(copy, y, x + 1);
		flood_fill(copy, y, x - 1);
	}
}

char	**ft_copy_map(t_game *game) //copiar el mapa en un char **
{
	int 	y;
	char **copy;
	
	copy = (char **)malloc(sizeof(char*) * (game->height + 1));
	if(!copy)
		return (NULL);
	y = 0;
	printf("Valor de height: %d\n", game->height); //DEPURACION
	while(y < game->height)
	{
		copy[y] = ft_strdup(game->map[y]); //copiar por cada fila
		if(!copy[y])
		{
			while(y > 0)
				free(copy[--y]);
			free(copy);
			return(NULL);
		}
		y++;
	}
	copy[y] = NULL;//para indicar en caso de error
	return(copy);	
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
				game->y = y;
				game->x = x;
				return;
			}
			x++;
		}
		y++;
	}
	game->y = -1;
	game->x = -1;//para indicar en caso de error
}

int	check_ec(t_game *game, char ** map)//comprobar que no tienes ni E ni C
{
	int y;
	int x;
	int numE;
	
	numE = 0;
	y = 0;
	while(map[y] != NULL)
	{
		x = 0;
		while(map[y][x] != '\0')
		{
			printf("Checking map[%d][%d]: %c\n", y, x, map[y][x]);
			if(map[y][x] == 'E')
				numE++;
			if(map[y][x] == 'C')
				game->total_coins++;
			x++;
		}
		y++;
	}
	printf("Total coins: %d, Exits: %d\n", game->total_coins, numE);
	if(game->total_coins != 0 || numE != 0)
	{
		printf("Error: Isolated item");
		return(-1); //en caso de error
	}
	return(0);
}

void	free_copy(t_game *game, char **map)//liberar el mpap en cualquier caso
{
	int	i;
	
	i = 0;
	if(map)
	{
		while(i < game->height)
		{
			if(map[i])
				free(map[i]);
			i++;
		}
		free(map);
	}
}
