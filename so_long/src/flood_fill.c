/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:50:35 by lginer-m          #+#    #+#             */
/*   Updated: 2024/10/22 21:43:13 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_game *game, char **copy, int y, int x)
{
	if (copy[y][x] != '1')
	{
		copy[y][x] = '1' ;
		flood_fill(game, copy, y - 1, x);
		flood_fill(game, copy, y + 1, x);
		flood_fill(game, copy, y, x + 1);
		flood_fill(game, copy, y, x - 1);
	}
}

char	**ft_copy_map(t_game *game) //copiar el mapa en un char **
{
	char	**copy;
	int		y;

	copy = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!copy)
		return (NULL);
	y = 0;
	while (y < game->height)
	{
		copy[y] = ft_strdup(game->map[y]);
		if (!copy[y])
		{
			while (y > 0)
				free(copy[--y]);
			free(copy);
			return (NULL);
		}
		y++;
	}
	copy[y] = NULL;
	return (copy);
}

void	found_player(t_game *game) //desde donde esta la P empezar flood fill
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->y = y;
				game->x = x;
				return ;
			}
			x++;
		}
		y++;
	}
	game->y = -1;
	game->x = -1;
}

int	check_ec(char **map)
{
	int	y;
	int	x;
	int	nume;
	int	numc;

	numc = 0;
	nume = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E' || map[y][x] == 'C')
				return (-1);
			x++;
		}
		y++;
	}
	return (0);
}

void	free_copy(t_game *game, char **map)//liberar el mpap en cualquier caso
{
	int	i;

	i = 0;
	if (map)
	{
		while (i < game->height)
		{
			if (map[i])
				free(map[i]);
			i++;
		}
		free(map);
	}
}
